class Dog():
    """A simple attempt to model a dog."""

    def __init__(self, name, age):
        """Initialize name and age attributes"""
        self.name = name
        self.age = age

    def sit(self):
        """Simulate a dog sitting in response to a command."""
        print(self.name.title() + " is now sitting.")

    def roll_over(self):
        """Simulte rolling over in response to a command."""
        print(self.name.title() + " rolled over!")


class restaurant():

    def __init__(self, restaurant_name, cuisine_type):
        # Estos son atributos
        self.restaurant_name = restaurant_name
        self.cuisine_type = cuisine_type

    def describe_restaurant(self):  # Esta funcion es un metodo
        print("The name of the restaurante is " + self.restaurant_name.title())
        print("The cuisine type is " + self.cuisine_type.title())

    def open_restaurant(self):
        print("The restaurant " + self.restaurant_name.title() + " is open")


class user():

    def __init__(self, first_name, last_name, gender, age):
        self.first_name = first_name
        self.last_name = last_name
        self.gender = gender
        self.age = age

    def describe_user(self):
        print("The name of the user is " +
              self.first_name.title() + " " + self.last_name.title())
        print("The gender of " + self.first_name.title() + " is " + self.gender)
        print("The age of " + self.first_name.title() + " is " + str(self.age))

    def greet_user(self):
        print("Welcome " + self.first_name.title() + " to my repository")


class car():

    def __init__(self, make, model, year):
        self.make = make
        self.model = model
        self.year = year
        self.odometer_reading = 0

    def get_descriptive_name(self):
        long_name = str(self.year) + ' ' + self.make + ' ' + self.model
        return long_name.title()

    def read_odometer(self):
        print("This car has " + str(self.odometer_reading) + " miles on it")


if __name__ == "__main__":

    my_new_car = car("audi", "a4", 2016)
    print(my_new_car.get_descriptive_name())
    my_new_car.read_odometer()

    my_dog = Dog('willie', 6)
    print("\nMy dog's name is " + my_dog.name.title() + ".")
    print("My dog is " + str(my_dog.age) + " years old.")
    my_dog.sit()
    my_dog.roll_over()

    your_dog = Dog('lucy', 3)  # Esto es una instancia
    print("\nYour dog's name is " + your_dog.name.title() + ".")
    print("Your dog is " + str(your_dog.age) + " years old.")
    your_dog.sit()

    fonda0 = restaurant("Celostina", "callejera")
    fonda0.describe_restaurant()
    fonda0.open_restaurant()

    fonda1 = restaurant("Bolo", "italiana")
    fonda1.describe_restaurant()
    fonda2 = restaurant("terry", "mexicana")
    fonda2.describe_restaurant()

    usuario = user("beto", "rodriguez", "male", 40)
    usuario.describe_user()
    usuario.greet_user()
