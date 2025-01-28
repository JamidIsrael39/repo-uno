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

def sum(lista):
	if lista == []:
		return 0
	else:
		return lista[0] + sum(lista[1:])

def cuenta(lista):
	if lista == []:
		return 0
	else:
		return 1 + cuenta(lista[1:])

def max(lst):
    if len(lst) == 0:
        return None
    if len(lst) == 1:
        return lst[0]
    else:
        max_num = max(lst[1:])
        return lst[0] if lst[0] > max_num else max_num

def quicksort(array):
  if len(array) < 2:
    # base case, arrays with 0 or 1 element are already "sorted"
    return array
  else:
    # recursive case
    pivot = array[0]
    # sub-array of all the elements less than the pivot
    less = [i for i in array[1:] if i <= pivot]
    # sub-array of all the elements greater than the pivot
    greater = [i for i in array[1:] if i > pivot]
    return quicksort(less) + [pivot] + quicksort(greater)

if __name__ == "__main__": 
	#countdown(5)
	#print(fact(4))
	arreglo = [1,20,3,4,5]
	print(arreglo)
	print(sum(arreglo))
	print(cuenta(arreglo))
	print(max(arreglo))
	print(quicksort(arreglo))
