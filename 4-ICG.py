import re

op = set("+-*/")
address = 100
count = 0

def arithematic(exp):
    global count
    symbols = []
    operators = []
    
    # Define operator precedence
    precedence = {
        '+': 1,
        '-': 1,
        '*': 2,
        '/': 2,
    }

    exp_list = exp.split()
    if len(exp_list) == 1:
        return exp_list[0]

    for i in exp_list:
        if i in op:
            # Pop operators from stack until top has lower precedence or stack is empty
            while len(operators) > 0 and precedence[operators[-1]] >= precedence[i]:
                count += 1
                e = "temp{0} = {1} {2} {3}".format(count, symbols.pop(-2), operators.pop(), symbols.pop())
                symbols.append("temp{}".format(count))
                print(e)
            operators.append(i)
        else:
            symbols.append(i)
    
    # Pop remaining operators from stack and generate 3-address code
    while len(operators) > 0:
        count += 1
        e = "temp{0} = {1} {2} {3}".format(count, symbols.pop(-2), operators.pop(), symbols.pop())
        symbols.append("temp{}".format(count))
        print(e)
        
    if len(symbols) == 2:
        temp = symbols.pop()
        print("{} = {}".format(symbols.pop(), temp))
    
    return symbols[0]


def relation(exp):
    global address
    tokens = re.split(r">=|<=|==|>|<", exp)
    operators = re.findall(r">=|<=|==|>|<", exp)

    print("{0} if {2} {3} {1} goto {4}".format(address, tokens.pop(), tokens.pop(), operators.pop(), address + 3))
    print("{} T := 0 ".format(address + 1))
    print("{} goto {}".format(address + 2, address + 4))
    print("{} T := 1".format(address + 3))
    address += 4
    print(address)

if __name__ == "__main__":
    while True:
        option = input("1 Assignment\n2 Arithmetic\n3 Relation\n4 Exit\nEnter choice : ")
        if option == "1":
            exp = input("Enter an expression : ")
            lhs, rhs = exp.split("=")
            temp = arithematic(rhs)
            print("{} = {}".format(lhs.strip(), temp))
        if option == "2":
            exp = input("Enter an expression : ")
            arithematic(exp)
        if option == "3":
            exp = input("Enter an expression : ")
            relation(exp)
        if option == "4":
            break
        print()


#assignment: x = 5 + 6
#arithmetic: b+c*d-e
#relation: a>c