#ifndef INCTHREAD_H
#define INCTHREAD_H

#include <QThread>

class IncThread : public QThread
{
  Q_OBJECT

public:
  IncThread();
  ~IncThread();

protected:
  void run();
};

#endif // INCTHREAD_H
