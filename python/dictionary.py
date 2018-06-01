phonebook = {
    "John" : 938477566,
    "Jack" : 938377264,
    "Jill" : 947662781
}

# write your code here
phonebook["kart"] = 900909123
phonebook["Jake"] = 900909124
# testing code
phonebook.pop("Jill")
if "Jake" in phonebook:
    print("Jake is listed in the phonebook.")
if "Jill" not in phonebook:
    print("Jill is not listed in the phonebook.")
for key in phonebook:
    print ("%s:%d" % (key, phonebook[key]))
