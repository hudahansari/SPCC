import re
import random

def create_table(expression):
    global symbol_table
    symbols = re.findall(r'[\w]+|[\W]', expression)
    symbol_table = {}
    # address = 0
    for symbol in symbols:
        if symbol.isalpha():
            address = random.randint(100, 9999)
            add_symbol(symbol, "identifier", address)
        else:
            address = random.randint(100, 9999)
            add_symbol(symbol, "operator", address)

def add_symbol_individual(symbol):
  global symbol_table
  if symbol.isalpha():
      address = random.randint(100, 9999)
      add_symbol(symbol, "identifier", address)  
  else:
      address = random.randint(100, 9999)
      add_symbol(symbol, "operator", address)
      
def add_symbol(symbol, type, address):
    global symbol_table
    symbol_table[symbol] = (address, type)

def search_symbol(symbol):
    global symbol_table
    if symbol in symbol_table:
        print("Symbol found:", symbol_table[symbol])
    else:
        print("Symbol not found:", symbol)

def remove_symbol(symbol):
    global symbol_table
    if symbol in symbol_table:
        del symbol_table[symbol]
        print("Symbol removed:", symbol)
    else:
        print("Symbol not found:", symbol)

def view_table():
    global symbol_table
    print("Symbol | Address | Type")
    for symbol, (address, type) in symbol_table.items():
        print("{} | {} | {}".format(symbol, address, type))

symbol_table = {}

while True:
    print("\n\n1. Create table")
    print("2. Search table")
    print("3. Enter symbol")
    print("4. Remove symbol")
    print("5. View table")
    print("6. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        expression = input("Enter expression: ")
        create_table(expression)
    elif choice == 2:
        symbol = input("Enter symbol to search: ")
        search_symbol(symbol)
    elif choice == 3:
        symbol = input("Enter symbol: ")
        # type = input("Enter type: ")
        # address = int(input("Enter address: "))
        add_symbol_individual(symbol)
    elif choice == 4:
        symbol = input("Enter symbol to remove: ")
        remove_symbol(symbol)
    elif choice == 5:
        view_table()
    elif choice == 6:
        break

