id_text_opened = open("id_tags.txt")
lst_of_authenticated_ids = [id for id in id_text_opened]

while True:
	input_id = input()
	#serial.strip() # basically converts int to string
	if input_id in lst_of_authenticated_ids:
		print(input_id + " is verified")
		door.open() #door is pseudocode
		""" 
		1. output 0/1/true or something if found
		2. transfer to Raspberry Pi 
		3. REMINDER: female to female jumper wires inside Raspberry Pi 
		4. Arduino then triggers the electric signal to the door unlock mechanism
		"""
	else: #register number
		print("Authentication required: ")
		allowed = input() #from remote?? Or someone who is verified
		if allowed:
			#add to database or write into text file
		else:
			print(input_id + " is not a registered user of the Berkeley Disability Lab")