#read file and allow appending (or do we want editing)
id_text_opened = open("id_tags_tester.txt", "a")

#lst of ids (ints)
#lst_of_authenticated_ids = [id for id in id_text_opened]

while True:
	input_id = input()
	#serial.strip() # basically converts int to string
	if input_id in id_text_opened:
		print(input_id + " is verified")
		"***door.open() #door is pseudocode***"
		""" 
		1. output 0/1/true or something if found
		2. transfer to Raspberry Pi 
		3. REMINDER: female to female jumper wires inside Raspberry Pi 
		4. Arduino then triggers the electric signal to the door unlock mechanism
		"""
		
	else: #register number
		print("Authentication required: ")
		allowed = input() #from remote?? Or someone who is verified by typing yes into monitor
		#could also press button for true/false signal
		if allowed is "yes": 
			#add to database or write into text file
			#currently we want to write directly into text file and SAVE it (and
			#autopush or we could manually push)
			id_text_opened.append(input_id)

		else:
			print(input_id + " is not a registered user of the Berkeley Disability Lab")
#we are now all done working w/ the file
id_text_opened.close()