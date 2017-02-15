#ifndef TASK_H
#define TASK_H

#include <QObject>

class task : public QObject
{
    Q_OBJECT
public:
    explicit task(QObject *parent = 0);

signals:

public slots:
};

#endif // TASK_H