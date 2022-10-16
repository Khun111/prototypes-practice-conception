from django.db import models

# Create your models here.
class School(models.Model):
    name = models.Charfied(max_length:400)

class Student(models.Model):
    pass