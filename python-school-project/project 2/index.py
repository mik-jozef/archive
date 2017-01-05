# Prints these statistics about debtors of the city Presov: number of debtors,
# total and average debt, largest single debt and top 10 indebted companies.

import re
from unicodedata import normalize
import xml.etree.ElementTree as ET
from unidecode import unidecode

# Names of debtors' attributes in the .xml file and their corresponding real names
attrName = {"col_0": "name", "col_2": "city", "col_3": "sum", "col_4": "currency"}

# Element containing data.
dataElement = list(list(ET.parse("Presov_zoznam_dlznikov.xml").getroot())[0])[1]

currencies = set()

# 0: firms, 1: people, 2: unidentified, n + 3: n + residents of Presov
numOfDebtors = [0] * 6
totalDebt = [0] * 6
highestDebt = [0] * 6

# Higher index - higher debt
topFirms = [(0, "(None)")] * 10

# 0: firm, 1: person, 2: unidentified
def whoAmI(name):
  if ("akciová spolocnosť" in name or "," in name or "a.s." in name
        or "s.r.o" in name or "spoločnosť s ručením obmedzeným" in name
        or re.search("[A-Z]{2}", name)):
    return 0
  
  # First_name Surname
  if re.search("[A-Z][a-z]+ [A-Z][a-z]+", unidecode(name)):
    return 1
  
  return 2

# Accepts xml node, returns dictionary of debtor data.
def getDebtorData(debtor):
  dict = {}
  
  for attr in debtor.items():
    if attr[0] in attrName:
      dict[attrName[attr[0]]] = attr[1]
  
  dict["sum"] = float(dict["sum"].replace(" ", "").replace(",", "."))
  
  return dict

def pad(value, num = 15):
  if type(value) is float:
    return ("{:>" + str(num) + ".2f}").format(value)
  
  return ("{:>" + str(num) + "}").format(value)

def printInfo(description, data):
  print(description)
  print("                  " + pad("celkom") + pad("v Presove"))
  print("Firmy:            " + pad(data[0]) + pad(data[3]))
  print("Ludia:            " + pad(data[1]) + pad(data[4]))
  print("Neidentifikované: " + pad(data[2]) + pad(data[5]))
  print("Spolu:            " + pad(data[0] + data[1] + data[2])
        + pad(data[3] + data[4] + data[5]) + "\n")

for debtor in dataElement:
  debtor = getDebtorData(debtor)
  
  currencies.add(debtor["currency"]);
  
  debtorCategory = whoAmI(debtor["name"])
  
  # if debtor is a firm, try to put the firm in my "top 10" list
  if debtorCategory == 0:
    for i in range(10):
      if topFirms[i][0] < debtor["sum"]:
        if i != 0:
          topFirms[i - 1] = topFirms[i]
        
        topFirms[i] = (debtor["sum"], debtor["name"])
      else:
        break
  
  numOfDebtors[debtorCategory] += 1
  totalDebt[debtorCategory] += debtor["sum"]
  
  if highestDebt[debtorCategory] < debtor["sum"]:
    highestDebt[debtorCategory] = debtor["sum"]
  
  if (debtor["city"] == "Prešov"):
    numOfDebtors[debtorCategory + 3] += 1
    totalDebt[debtorCategory + 3] += debtor["sum"]
    
    if highestDebt[debtorCategory + 3] < debtor["sum"]:
      highestDebt[debtorCategory + 3] = debtor["sum"]

comma = False

for i in currencies:
  if comma:
    currenciesStr += ", " + i
  else:
    currenciesStr = i
    comma = True

printInfo("Pocet dlznikov", numOfDebtors)
printInfo("Celkovy dlh", totalDebt)
printInfo("Priemerny dlh", [totalDebt[i] / numOfDebtors[i] for i in range(6)])
printInfo("Najvacsi dlh jednej firmy/osoby", highestDebt)

print("Ludia dlzia Presovu v nasledujucich menach: " + currenciesStr + ".\n")

print("Top 10 najzadlzenejsich firiem:")
for i in range(10):
  print(pad(i + 1, 2) + ". " + unidecode(topFirms[9 - i][1]))