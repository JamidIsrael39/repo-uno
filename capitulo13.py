def add(x, y):
	"""Suma de dos numeros"""
	return x + y

def subtract(x, y):
	"""Sustracts two numbers"""
	return x - y

def multiply(x, y):
	"""Multiplicacion de dos numeros"""
	return x * y

def divide(x, y):
	"""Division de dos numeros"""
	return x / y

def divide_integer(x, y):
	"""Division entera de dos numeros"""
	return x // y

def module(x, y):
	"""Modulo de dos numeros"""
	return x % y

def power(x, y):
	"""Potencia de un numero multiplicado por 3"""
	return 3*x ** y

def check_if_user_has_finished():
	"""
	Revisa si el usuario quiere finalizar o no
	Realiza algunas verificaciones a la entrada
	"""
	ok_to_finish = True
	user_input_accepted = False
	while not user_input_accepted:
		user_input = input('¿Deseas finalizar? (s/n): ')
		if user_input == 's':
			user_input_accepted = True
		elif user_input == 'n':
			ok_to_finish = False
			user_input_accepted = True
		else:
			print('Solamente ingresa (s/n), trata de nuevo')
	return ok_to_finish
def get_operation_choice():
	input_ok = False
	while not input_ok:
		print('Menu, las opciones son:')
		print('\t1. Suma')
		print('\t2. Resta')
		print('\t3. Multiplicacion')
		print('\t4. Division')
		print('\t5. Modulo')
		print('\t6. Potencia de numero por 3')
		print('-----------------------')
		user_selection = input('Realiza una seleccion: ')
		if user_selection in ('1', '2', '3', '4', '5', '6'):
			input_ok = True
		else:
			print('Dato ingresado incorrecto (debe ser 1 - 6)')
	print('---------------')
	return user_selection

def get_division_choice():
	input_ok = False
	while not input_ok:
		print("Las opciones son:")
		print("\tA Division flotante")
		print("\tB Division entera")
		print("-----------------------")
		user_selection = input("Realiza una seleccion: ")
		if user_selection in ('A', 'B'):
			input_ok = True
		else:
			print('Dato ingresado incorrecto (debe ser A o B)')
	print('----------------')
	return user_selection

def get_numbers_from_user():
	num1 = get_integer_input('Ingresa el primer numero: ')
	num2 = get_integer_input('Ingresa el segundo numero: ')
	return num1, num2

def get_integer_input(message):
	value_as_string = input(message)
	while not value_as_string.isnumeric():
		print('El dato debe ser un entero')
		value_as_string = input(message)
	return int(value_as_string)

def get_float_numbers(message):
	value_as_float = input(message)
	while not value_as_float.replace(".", "").isnumeric():
		print('El dato no es valido')
		value_as_float = input(message)
	return float(value_as_float)

def get_float_numbers_from_user():
	numf1 = get_float_numbers('Ingresa el primer numero: ')
	numf2 = get_float_numbers('Ingresa el segundo numero: ')
	return numf1, numf2
"------------------Ejecucion del programa principal--------------------"
if __name__ == '__main__':
	print('Aplicacion de calculadora basica')
	finished = False
	while not finished:
		result = 0
		menu_choice = get_operation_choice()
		if menu_choice == '4':
			print("¿Deseas realizar division flotante o de entero?")
			division_choice = get_division_choice()
			if division_choice == 'A':
				n1, n2 = get_float_numbers_from_user()
				result = divide(n1, n2)
				print('Resultado:', result)
			elif division_choice == 'B':
				n1, n2 = get_numbers_from_user()
				result = divide_integer(n1, n2)
				print('Resultado:', result)
		else:
			n1, n2 = get_float_numbers_from_user()
			#Sleccionar la operacion
			if menu_choice == '1':
				result = add(n1, n2)
			elif menu_choice == '2':
				result = subtract(n1, n2)
			elif menu_choice == '3':
				result = multiply(n1, n2)
			elif menu_choice == '5':
				result = module(n1, n2)
			elif menu_choice == '6':
				result = power(n1, n2)
			print('Resultado:', result)
		print('================')
		finished = check_if_user_has_finished()
			#Ver si el usuario desea finalizar
	print('Bye')
