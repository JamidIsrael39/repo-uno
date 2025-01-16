def findsmallest(arr):
        smallest = arr[0]
        print("smallest previo: ", smallest)
        smallest_index = 0
        print("smallest_index: ", smallest_index)
        for i in range(1, len(arr)):
                print("i = ", i)
                if arr[i] < smallest:
                        smallest = arr[i]
                        print("smallest nuevo: ", smallest)
                        smallest_index = i
                        print("smallest_index nuevo: ", smallest_index)
        return smallest_index

def selectionsort(array):
        newarray = []
        copiedarray = list(array)
        for i in range (len(copiedarray)):
                smallest = findsmallest(copiedarray)
                print("smallest de la funcion sort: ", smallest)
                print("Arreglo previo: ", copiedarray)
                newarray.append(copiedarray.pop(smallest))
                print("El nuevo arreglo es: ", newarray)
        return newarray

if __name__ == "__main__":
  array = [5,3,6,2,10]
  sorted = selectionsort(array)
  print("El arreglo original es: ", array)
  print("El arreglo ordenado es: ", sorted)

