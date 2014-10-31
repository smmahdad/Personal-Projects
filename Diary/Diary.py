import datetime
import os.path
import getpass

#TODO: 	Update All with new encryption for encyrption updates and save data.
#			-work on applying new encryption
#	   	Figure out a new encryption to use (maybe base it off the date (day/month))
#		


#Creation of a diary entry that always starts with an encrypted date before encrypting the rest
#of the entry
def diary_entry(fname):
	#encrypt today's date
	day, month, year = encrypted_date()
	#have the entry start with a consistent message
	entry = '\n\nBeg: ' + str(day) + ' ' + str(month) + ' ' + str(year) + '\n'
	#Gather the input from user
	entry += input("Write your thoughts:\n\n")
	#end the entry in a consistent manner as well
	entry += '\nFIN!\n'
	#encrypt everything saved in entry
	encrypted_entry = encryption(entry)
	#append this entry to the file name provided (fname)
	f = open(fname, 'a')
	f.write(encrypted_entry)
	f.close()

#encrypt the date by altering everything but day because of month technicalities
def encrypted_date(day=0, month=0, year=0):
	if year == 0:
		now = datetime.datetime.now()
		day = now.day
		month = now.month
		year = now.year

	#really simple encryption that I am still trying to make more complexed
	return day, month * 2, year - 1286

#decrypt the date given
def decrypt_date(day, month, year):
	return day, month // 2, year + 1286

#checks to see the date in the file_name matches and if so returns true
def check_date(file_name, entry):
	f = open(file_name, 'r')
	for line in f:
		if line == entry:
			f.close()
			return True
	f.close()
	return False

#retrieves the entry by date and our ending pattern of FIN!
#also gathers all of the entries that are listed under the date given
def find_entry(file_name, entry):
	f = open(file_name, 'r')
	start_reading = False
	result = ''
	end = encryption("FIN!\n")
	for line in f:
		if line == entry:
			start_reading = True
		elif start_reading and line != end:
			result += line
		elif start_reading and line == end:
			start_reading = False
	f.close()
	return result

#encryption for anything given in as entry
#simple encryption by changing the letter by one. Need to change this to make more complexed
def encryption(entry):
	new_entry = ''
	for letter in entry:
		if letter != '\n': 
			val = chr(ord(letter) + 1)
			if val != '\n':
				new_entry += val
			else:
				new_entry += chr(123)
		else:
			new_entry += letter
	return new_entry


#decrypting our encryption
def decryption(entry):
	new_entry = ''
	for letter in entry:
		if letter != '\n' and letter != chr(123):
			new_entry += chr(ord(letter) - 1)
		elif letter == chr(123):
			new_entry += chr(ord('\n') - 1)
		else:
			new_entry += '\n'

	return new_entry

#Create a new diary and checks to see if the diary already exists.
#Allows user to set password
def create_diary():
	diary_name = input("Name of your diary? ")
	if os.path.isfile(diary_name):
		print("Error: File already exists!")
	else:
		f = open(diary_name, 'w')
		password = getpass.getpass("What password would you like? ")
		encrypted_password = encryption(password)
		f.write(encrypted_password)
		f.close()

#function the ensure that the password is the password in the diary.
def check_password(file_name):
	password = getpass.getpass("What is your password? ")
	f = open(file_name, 'r')
	file_password = f.readline()
	if encryption(password) + '\n' == file_password or encryption(password) == file_password:
		f.close()
		return True
	else:
		f.close()
		return False

#console based application to access main and the functions.
def main():
	data = input("Entry[0], Create[1], Read[2]: ")
	if data == '1':
		create_diary()

	elif data == '2':
		file_name = input("Which diary? ")

		if os.path.isfile(file_name):

			if check_password(file_name):
				total = input("Which entry? (dd mm yyyy) ")
				#parse the input given to a uniformed date, month, year standard
				day, month, year = total[0] + total[1], total[3] + total[4], total[6] + total[7] + total[8] + total[9]
				day, month, year = encrypted_date(int(day), int(month), int(year))
				entry_string = encryption('Beg: ' + str(day) + ' ' + str(month) + ' ' + str(year) + '\n')
				#check if the date is valid in the diary
				if check_date(file_name, entry_string):
					entry = find_entry(file_name, entry_string)
					print('\nYour Journal Entry:\n\n' + decryption(entry))
				else:
					print("No entries at that date.")

			else:
				print("Password is wrong!")

		else:
			print("No diaries named that.")

	elif data == '0':
		file_name = input("Which diary? ")
		if os.path.isfile(file_name):
			if check_password(file_name):
				diary_entry(file_name)
			else:
				print("Password is wrong!")
	else:
		print("Incorrect selection. Goodbye.")
if __name__ == "__main__":
	main()












