# this file reads in a data or csv file. It can read a list and counts the occurrences of the words in a data or text file and
# the unique name is the key and the occurrence count integer is the value. It prints out a histogram for the data


text_file = r"socialmedia.txt"
inputname = "socialmedia.dat"   #save csv as file

# create empty lists used to count occurrence  of words
list = []

# create  empty list with  to store unique words
new_list = []

# create dictionary to assist with assigning values to items for reference later
dict1 ={}
lowercaseDict = {}
uniqueWordsDict = {}

# read text file
with open(text_file, 'r') as myfile:

    datfile = myfile.readlines()
    for row in datfile:

        #uniqueWordsDict[row.strip()] = uniqueWordsDict.get(row.strip(), 0) + 1
        row.split(' ')

        # append each word to empty list "list" for counting occurrences
        list.append(row.strip("\n"))

        for word in list:
            freq = list.count(word)

            # add word as key and frequency as value for our file reference dictionary
            dict1.update({word:freq})
            lowercaseDict.update({word.lower():freq})

myfile.close()

uFile = open(text_file, 'r')
for line in uFile:
    uniqueWordsDict[line.strip()] = uniqueWordsDict.get(line.strip(), 0) + 1
uFile.close()
# write the dat file
with open(inputname, 'w') as outFile:

    for key, value in sorted(uniqueWordsDict.items()):
        stringOut = key + " " + str(value)
        outFile.write(stringOut + "\n")

outFile.close()


# menu item 2 print product stats given a specific product, print the number puchased.
def getStats(userString): #

    userString = userString.lower()
    if userString in lowercaseDict:

        for key, value in lowercaseDict.items():

            if key == userString.lower():
                valueReturn = value

    else:
        valueReturn = 0

    print(valueReturn)
    return valueReturn


# method and menu item 3 print a histogram for each item with asterisks denoting the number of items purchased
def getHistogram():
    print('')
    for key, value in dict1.items():
        print(key, "(", end ='')
        print(value, end=') ')

        for i in range(value):
            print ("*", end='')

        print('')


#  menu item 1 prints full dictionary as a list of all inventory items.
def SocialMediaList():

    for k, v in dict1.items():
        print(k, v)
