class Animalia:
    def can_breathe():
        return 'animals can breathe'

class Pisces(Animalia):
    pass

class Mammalia(Animalia):
    pass

print(Mammalia().can_breathe)