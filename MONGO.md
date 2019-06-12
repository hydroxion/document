## Mongo

This is a Mongo cheatsheet for the basic usage of Mongo.

### Setup

<details>
<summary>Install the Mongo</summary>

```sh
$ sudo docker-compose up
```
</details>

<details>
<summary>Start the Mongo service</summary>

```sh
$ docker start mongo-container
```
</details>

<details>
<summary>
Open the Mongo CLI</summary>

```sh
$ docker exec -it mongo-container mongo
```
</details>

### Cheatsheet

Inside the Mongo CLI, run the commands below.

```sh
# List all commands
> db.help()

# Get statistics about the server
> db.stats()

# Show all databases. To display a database, its required to insert
# at least one document into it
> show dbs

# Create / use a database
> use name

# See the current database
> db

# Remove the database in use, if no database is selected,
# the test database is removed
> db.dropDatabase()

# Create a collection, name is a required string, while options is
# a optional document, containing:
#
# capped (bool - fixed size collection that automatically overwrites
# its oldest entries when it reaches its maximum size, require the
# size parameter)
# 
# autoIndexId (bool - automatically create index on _id field)
#
# size (number - specifies a maximum size in bytes for a capped collection)
#
# max (number - specifies the maximum number of documents allowed in a
# capped collection)
> db.createCollection(name, options)

# Show collections
> show collections

# Remove a collection
> db.collection-name.drop()

# Data types https://docs.mongodb.com/manual/reference/bson-types/

# Create a collection / insert into a collection. To insert multiple documents
# in a single query, you can pass an array of document. The save() function
# does the same as the insert()
> db.collection-name.insert({'key1': 'value1'})

# Find all documents of a collection, in a non-structured way.
# 
# Operations: 
#
# equality = {<key>: <value>}
#
# less than < {<key>: {$lt: <value>}}
#
# less than equal <= {<key>: {$lte: <value>}}
#
# greater than > {<key>: {$gt: <value>}}
#
# greater than equal >= {<key>: {$gte: <value>}}
#
# not equals != {<key>: {$ne: <value>}}
#
# Logical operations:
#
# and, multiple keys separated by ',' is considered a and condition
# 
# {
#     $and: [
#         {key1: value1}, {key2: value2}
#     ]
# }
#
# or
#
# {
#     $or: [
#         {key1: value1}, {key2: value2}
#     ]
# }
> db.collection-name.find()

# Find all documents of a collection, in a structured way
> db.collection-name.find().pretty()

# Find a only one document
> db.collection.findOne()

# Update a document in a existing document. The update() method updates the values
# in the existing document while the save() method replaces the existing document
# with the document passed in save() method
# 
# db.collection-name.update(criteria, data)
# 
# By default Mongo only updates one document, to update multiple documents its
# necessary to set multi to true
#
# db.collection-name.update(criteria, data, {multi: true})
# 
# The syntax to save():
#
# db.collection-name.save({_id: ObjectId(), data})
> db.collection-name.update({'key1': 'value1'}, {$set: {'key2':'value2'}})

# Remove a document. To specify the remotion of only one document set the justOne
# (optional) to true or 1
> db.collection-name.remove(criteria)

# Projection means selecting only the necessary data rather than selecting
# whole of the data of a document. The find() method, accepts second optional
# parameter that is list of fields that you want to retrieve.  To limit this,
# you need to set a list of fields with value 1 or 0. 1 Is used to show the
# field while 0 is used to hide the fields.
> db.collection-name.find({}, {key: 1})

# Limit the number of documents returned
> db.collection-name.find().limit(number)

# Sort documents. To specify sorting order 1 and -1 are used. 1 is used for
# ascending order while -1 is used for descending order. The default order is
# ascending order
> db.collection-name.find().sort({key: 1})

# Create indexes. Indexes store a portion of the data set in an easy-to-traverse
# form, to make efficient resolution queries without scan every document.
#
# 1 Is for ascending order. To create index in descending order you need to use -1.
#
# Multiple fields are can be used to create an index. Besides multiple fields, options
# are available:
#
# background (bool - builds the index in the background)
#
# unique (bool - creates a unique index, that don't accept key (s) that match an existing
# value in the index)
#
# name (string - the index name)
#
# dropDups (bool - creates a unique index on a field that may have duplicates)
#
# sparse (bool - references documents with the specified field, uses less space, but behave
# differently in some cases)
#
# expireAfterSeconds (integer - Specifies a value, in seconds, as a TTL to control how long
# Mongo retains documents in this collection)
#
# v (index version - the index version number, depends on Mongo, that is running, version)
#
# weights (document - number ranging from 1 to 99,999 and denotes the significance of the
# field relative to the other indexed fields in terms of the score)
#
# default_language (string - language that determines the list of stop words and the rules
# for the stemmer and tokenizer)
# 
# language_override (string - specify the name of the field in the document that contains,
# the language to override the default language)
> db.collection-name.ensureIndex({key: 1})
```