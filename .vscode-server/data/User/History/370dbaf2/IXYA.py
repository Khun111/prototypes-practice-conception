from django.db import models
from datetime import datetime

# Create your models here.
class School(models.Model):
    name = models.CharField(max_length=400)
    address = models.CharField(max_length=400)
    postal_code = models.IntegerField()

    def __str__
class Student(models.Model):
    School = models.ForeignKey(School, on_delete=models.CASCADE)
    first_name = models.CharField(max_length=40)
    last_name = models.CharField(max_length=40)
    age = models.IntegerField()
    date_of_resumption = models.DateField(default=datetime.today)