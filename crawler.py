#!bin/python3

import urllib.request
import time
from html.parser import HTMLParser

class MyHTMLParser(HTMLParser):
	def __init__(self):
		super().__init__()
		self.catch = False
		self.startCollecting = False
		self.words = []

	def handle_starttag(self, tag, attrs):
		#print ("Encountered a start tag:", tag)
		if tag == "table":
			self.startCollecting = True
		elif self.startCollecting and tag == "a":
			self.catch = True

	def handle_endtag(self, tag):
		#print ("Encountered an end tag :", tag)
		if tag == "table":
			self.startCollecting = False
			self.catch = False
		elif self.startCollecting and tag == "a":
			self.catch = False

	def handle_data(self, data):
		#print("Encountered some data  :", data)
		if self.catch and bool(data.strip()):
			#print("Catched: ",data.strip())
			self.words.append(data.strip())


dictionaryFile = open("dictionary_crawled", 'w+')

for i in range(11,33):

	previousWord = ''
	for j in range(1,200):
		time.sleep(1)
		page = "http://anagramscramble.com/wordsbylength/%d?page=%d" %(i,j)
		print("Enter: ",page)
		response = urllib.request.urlopen(page).read()

		parser = MyHTMLParser()
		parser.feed(response.decode('utf-8'))

		if len(parser.words) == 0 or parser.words[0] == previousWord:
			print("Same!!!!!!!!!!!!!")
			break
		previousWord = parser.words[0]

		for word in parser.words:
			dictionaryFile.write(word + "\n")

dictionaryFile.close()
#
# f.write(decoded)
