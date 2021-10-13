import unicodedata
import re
from os import path

blocks = 1500

ptoi = lambda p : int("0x" + p, 16)

def genCodeBlocks():
	code = open("uniblocks.txt", 'w')
	web = open("Blocks.txt", 'r')
	line = web.readline()
	while line:
		line = re.split(r';', line)
		line = re.split(r"\.\.", line[0])
		if len(line) == 2:
			line = line[0] + "." + line[1] + '\n'
			code.write(line)
		line = web.readline()
	code.close()
	web.close()

if not path.exists("blocks"):
	genCodeBlocks()

code = open("uniblocks.txt", "r")
unichars = open("unichars.txt", "w")
line = code.readline()

while line and blocks > 0:
	blocks -= 1
	block = re.split(r"\.", line[:-1])
	start = ptoi(block[0])
	end = ptoi(block[1])
	
	for i in range(start, end):
		try:
			unichars.write(chr(i))
		except UnicodeEncodeError:
			print("Skipping block " + hex(start) + " . " + hex(end))
			line = code.readline()
			break
	unichars.write('\n')
	line = code.readline()
