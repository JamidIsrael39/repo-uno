def countdown(i): 
	print(i)
	if i <= 1:
		return
	else:
		countdown(i - 1) 

def fact(x): 
	if x == 1: 
		return 1 
	else: 
		return x * fact(x -1) 

if __name__ == "__main__": 
	countdown(5)
	print(fact(4))
