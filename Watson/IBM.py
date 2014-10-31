import urllib
import urllib.parse
import urllib.request
import json as m_json

query = input ( "What's your question?: " )
query = urllib.parse.urlencode ( { 'q' : query } )
response = urllib.request.urlopen ( 'http://ajax.googleapis.com/ajax/services/search/web?v=1.0&' + query ).read()
json = m_json.loads ( response.decode() )

results = json [ 'responseData' ] [ 'results' ]
answer = results[0]
title = answer['title']
stri = ''

title = "What is " + title.replace('Wikipedia', "")
final_answer = title.replace('the free encyclopedia', '')
final_answer = final_answer.replace("- ,", '')
final_answer = final_answer.replace("<b>", '')
final_answer = final_answer.replace("</b>", '')

print(final_answer)