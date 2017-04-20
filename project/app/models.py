from __future__ import unicode_literals
from django.db import models
from rest_framework import serializers

class Sensor(models.Model):
	created = models.DateTimeField(auto_now_add=True)
	updated = models.DateTimeField(auto_now=True)
	memo = models.CharField(max_length=100)

class Event(models.Model):
	created = models.DateTimeField(auto_now_add=True)
	message = models.CharField(max_length=10)


class CustomerSerializer(serializers.ModelSerializer):
	class Meta:
		model = Customer
		fields = ('name','dob')