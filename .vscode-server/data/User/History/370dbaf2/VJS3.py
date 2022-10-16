from django.db import models

# Create your models here.
class School(models.Model):
    name = models.CharField(max_length=400)
    address = models.CharField(max_length=400)
    postal_code = models.IntegerField()
class Student(models.Model):
    School = models.ForeignKey(School, on_deete=models.CASCADE)
    first_name = models.CharField(max_length=400)
     = models.CharField(max_length=400)
    postal_code = models.IntegerField()