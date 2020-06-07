#ifndef LITE_ITERATOR_H
#define LITE_ITERATOR_H

#include "stdcxx/LiteObject.h"
#include "stdcxx/LiteCollection.h"

class LiteIterator : public LiteObject {
public:
  virtual void reset() = 0;

  virtual LiteObject *getNextObject() = 0;
};

class LiteCollectionIterator : public LiteIterator {
protected:
  const LiteCollection *collection;
  void *innerIterator;

public:
  static LiteCollectionIterator *withCollection(const LiteCollection *inCollection);

public:
  virtual void release();

public:
  virtual void reset();

  virtual bool initWithCollection(const LiteCollection *inCollection);

  virtual LiteObject *getNextObject();
};

#endif