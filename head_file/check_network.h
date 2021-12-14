#ifndef CHECK_NETWORK_H
#define CHECK_NETWORK_H

#include <QThread>

class check_network : public QThread
{
public:
    explicit check_network(QObject *parent = nullptr);


protected:
    void run();
};

#endif // CHECK_NETWORK_H
