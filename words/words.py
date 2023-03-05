import string
import sys 

input, print = sys.stdin.readline, sys.stdout.write

def processInput():
    userInput = input()
    userInput = (userInput[1:-2]) # remove square brackets
    splitStr = userInput.split("', ") # splits string array by comma
    returnArray = []

    for index in range(len(splitStr)):
        if index == len(splitStr)-1:
            lastStr = (splitStr[index])[1:-1]
            returnArray.append(lastStr)
            break
        newStr = (splitStr[index])[1:]
        returnArray.append(newStr)
    # adds all strings to new list object

    return returnArray



def longest(array):
    newArray = [val.translate(str.maketrans('', '', string.punctuation)) for val in array]
    longestStr = max(newArray, key=len)
    stringIndex = newArray.index(longestStr)
    
    ls = array[stringIndex] # output 1
    print(ls + '\n')

    lsSplit = ls.split(" ")
    lw = max(lsSplit, key=len)
    
    occurencesCounter = lsSplit.count(lw)
    if occurencesCounter == 1: # output 2
        print(lw)
    else:
        print(lw[::-1])


def words(func1, func2):
    arr = func1()
    func2(arr)

# testArray1 = ['i am a', 'i am a contestant', 'i am a contestanb']
# testArray2 = ['welcome', 'welcome to UCC', 'welcome to UCC, welcome']

#longest(testArray1)

# Output:
# i am a contestant
# contestant

#longest(testArray2)

# Output:
# welcome to UCC, welcome
# emoclew

#wordsArray = processInput()
#longest(wordsArray)

words(processInput, longest)
