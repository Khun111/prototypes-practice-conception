class Animal:
    animal_type = 'various'
    
    def __init__(self, name, legs):
        self.name = name
        self.legs = legs
        print(f"Animal {name} has {legs} legs")
    def can_run(self):
        print(f"Animal {self.name} can run with {self.legs} legs")
    @classmethod
    def can_see(cls):
        print('Animals can see!')
    @staticmethod
    def tail_wiggle():
        print('animal can wiggle it\'s tail')

print(Animal.animal_type)
animal_type1 = Animal('hen', 2)
animal_type2 = Animal('dog', 4)
print(animal_type1.animal_type)
animal_type1.can_run()
animal_type2.tail_wiggle()
animal_type1.tail_wiggle()