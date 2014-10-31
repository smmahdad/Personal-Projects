import datetime
import requests                                                             
import lxml.html   

#use to gauge what day today is and then use the string to search through yelp's html
dict_day = {1: 'Mon', 2: 'Tue', 3: 'Wed', 4: 'Thu', 5: 'Fri', 6: 'Sat', 7: 'Sun'}

#today is a datetime object with today's information
#opening is a datetime object with the opening times for the restaurant
#closing is a datetime object with the closing times for the restaurant
def is_open(today, opening, closing):
	#check if current time is later than opening time
	if today.hour >= opening.hour:
		#check if we are under the closing time
		if today.hour < closing.hour:
			return True
		#check if it is the same hour for closing
		elif today.hour == closing.hour:
			#check if we still have time to rush to the restaurant
			if today.minute < closing.minute:
				return True
			else:
				return False
		else:
			return False
	#if the time right now is less than the opening time
	else:
		#check if closing is at a time 'earlier' than opening time. (Like 2AM)
		if closing.hour < opening.hour:
			#check if our current time is less than the 2AM closing example
			if opening.hour < closing.hour:
				return True
		return False


def check_opening_time(html):
	#i is used for indicating where we are in the html tag
	i = 0
	#passed_semi is to indicate when we pass the colon in time
	passed_semi = False
	#next_round is used to indicate when we have to grab the digits
	next_round = False
	#count is to decipher whether it is pm or am for our datetime
	count = 0
	#once is to check if we have already searched the opening time
	once = False
	#answer is the return value of tuples for opening and closing [(hour, minutes, bool for am/pm)]
	answer = []
	#hour to hold the hour for  datetime
	hour = 0
	#minutes to hold the minutes for datetime
	minutes = 0
	#am to tell whether or not the time is in the afternoon or morning
	am = True
	#go through the html page character by character
	for word in html:
		#if i is greater than length of the opening tage then parse the time
		if i >= length:
			if i == length:
				hour = int(chr(word))
			elif i == length + 1:
				if chr(word) != ':':
					hour = hour * 10 + int(chr(word))
				else:
					passed_semi = True
			elif i == length + 2:
				if passed_semi:
					minutes = int(chr(word))
					passed_semi = False
				else:
					passed_semi = True
			elif i == length + 3:
				if passed_semi:
					minutes = int(chr(word))
					passed_semi = False
				else:
					minutes = minutes * 10 + int(chr(word))
					next_round = True
			elif i == length + 4 and not next_round:
				minutes = minutes * 10 + int(chr(word))
				next_round = True
				passed_semi = False
			elif next_round and not once:
				count += 1
				if count == 2:
					if chr(word) == 'p':
						hour + 12
						am = False
				if count == closing_length:
					i = length - 1
					next_round = False
					once = True
					answer += [(hour, minutes, am)]
					count = 0
			elif once:
				count += 1
				if count == 2:
					if chr(word) == 'p':
						hour + 12
						am = False
					return answer + [(hour, minutes, am)]
			else:
				i = 0
			i += 1
		#if word is the same letter as that of the string for the tag, increment i
		elif chr(word) == opening_idea[i]:
			i += 1
		#if the tag does not match opening set i to 0
		else:
			i = 0
	#return the empty list of answer if nothing was executed
	return answer

#global now time, and find the day
now = datetime.datetime.now()
word_day = dict_day[now.isoweekday()]

#tag prior to the opening times for that day
opening_idea = '<th scope="row">' + word_day + '</th>\n                        <td>\n                            <span class="nowrap">'
length = len(opening_idea)
#tag prior to the closing times for that day
closing_idea = ' am</span> - <span class="nowrap">'
closing_length = len(closing_idea)

#takes in the list of tuples and prints whether or not the restaurant is open.
def print_answer(answer, search):
	#checks if am or pm. If pm execute body and add any number above 12 by 12
	if not answer[0][2]:
		if answer[0][0] == 12:
			opening = datetime.time(answer[0][0], answer[0][1])
		else:
			opening = datetime.time(answer[0][0] + 12, answer[0][1])
	#if am then use modulus 12 to make 12AM really 00 for the datetime object
	else:
		opening = datetime.time(answer[0][0] % 12, answer[0][1])

	#checks if am or pm like above
	if not answer[1][2]:
		if answer[1][0] == 12:
			closing = datetime.time(answer[1][0], answer[1][1])
		else:
			closing = datetime.time(answer[1][0] + 12, answer[1][1])
	#makes closing time adherent to previous 12AM rule
	else:
		closing = datetime.time(answer[1][0] % 12, answer[1][1])

	#check if the restaurant is open. if so print a success
	if is_open(now, opening, closing):
		print("Enjoy eating at " + search + " because it is open!!")
	#if the restaurant is not open, allow user to search a new restaurant.
	else:
		print("Boo, " + search + " is closed :[")
		find_food()


#Asks user what restaurant they would like, scrapes yelp to find if the restaurant has an hours table,
#and calls other functions to finish the work
def find_food():
	#setting up the URL and locations
	BASE_URL = "http://www.yelp.com"                                                                                             
	location ="University of California, Berkeley"   
	#Asks user what restaurant
	search = input("What Restaurant? ") 

	#parses the location and search for yelp's url concantenations.                                                    
	term = search.replace(" ","+")                                              
	place = location.replace(",","%2C").replace(" ","+")                        
	query = BASE_URL + "/search?find_desc="+term+"&find_loc="+place+"&ns=1#start=0"

	#grabs the html and scrapes/collects all results from search
	html = requests.get(query).content                                          
	tree = lxml.html.fromstring(html)
	results = tree.xpath("//span[@class='indexed-biz-name']/a[@class='biz-name']/@href")

	#search through the first result and grab the html from that page
	html = requests.get(BASE_URL + results[0]).content
	tree = lxml.html.fromstring(html)
	results = tree.xpath(".//table [@class='table table-simple hours-table']")

	hour = 0
	minutes = 0
	#check to see if we have any hits with the table for hours in the html
	if results:
		#check to make sure results[0] is valid and the html didn't fail to load
		if results[0] is not None:
			#call function to gather the times for opening and closing
			answer = check_opening_time(html)
			#prints the answer if the restaurant is open or not.
			print_answer(answer, search)
		else:
			print("Sorry, couldn't find their hours.")
	else:
		print("Sorry, couldn't find their hours.")


find_food()

















