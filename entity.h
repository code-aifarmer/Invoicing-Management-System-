#ifndef ENTITY_H
#define ENTITY_H

#include<QObject>

class Entity : public QObject
{
public:
    Entity();
    QString toString();
};

class Goods : public Entity {
private:
    int gid;
    QString name;
    double purchase_price;
    double sale_price;
    int stock;
    QString purchase_date;
    QString purchaser;
    QString phone;

public:
    Goods(int gid, const QString &name, double purchase_price, \
          double sale_price, int stock, const QString &purchase_date, \
          const QString &purchaser, const QString &phone);

    int getGid() const;
    const QString &getName() const;
    void setName(const QString &newName);
    double getPurchase_price() const;
    void setPurchase_price(double newPurchase_price);
    double getSale_price() const;
    void setSale_price(double newSale_price);
    int getStock() const;
    void setStock(int newStock);
    const QString &getPurchase_date() const;
    void setPurchase_date(const QString &newPurchase_date);
    const QString &getPurchaser() const;
    void setPurchaser(const QString &newPurchaser);
    const QString &getPhone() const;
    void setPhone(const QString &newPhone);

};

class Order : public Entity {
private:
    int oid;
    QString goods_name;
    int goods_num;
    QString buyer;
    QString address;
    QString phone;
    QString order_date;
    int gid;

public:
    Order(const QString &goods_name, int goods_num, const QString &buyer, const QString &address, const QString &phone, const QString &order_date, int gid);
    Order(int oid, const QString &goods_name, int goods_num, const QString &buyer, const QString &address, const QString &phone, const QString &order_date, int gid);

    int getOid() const;
    const QString &getGoods_name() const;
    void setGoods_name(const QString &newGoods_name);
    int getGoods_num() const;
    void setGoods_num(int newGoods_num);
    const QString &getBuyer() const;
    void setBuyer(const QString &newBuyer);
    const QString &getAddress() const;
    void setAddress(const QString &newAddress);
    const QString &getPhone() const;
    void setPhone(const QString &newPhone);
    const QString &getOrder_date() const;
    void setOrder_date(const QString &newOrder_date);

    int getGid() const;
    void setGid(int newGid);
};

class Pair : public Entity {
private:
    QString name;
    int sum;
public:
    Pair(const QString &name, int sum);

    const QString &getName() const;
    void setName(const QString &newName);
    int getSum() const;
    void setSum(int newSum);

    bool operator> (Pair& p);
    bool operator< (Pair& p);
    bool operator== (Pair& p);
};

class Cargo : public Entity {
private:
    int gid;
    QString name;
    double purchase_price;
    double sale_price;
    int stock;
    QString purchase_date;
    QString saller;

public:
    Cargo() {}
    Cargo(const QString &name, double purchase_price, double sale_price, int stock, const QString &purchase_date);
    Cargo(int gid, const QString &name, double purchase_price, double sale_price, int stock, const QString &purchase_date, const QString &saller);

    int getGid() const;
    void setGid(int newGid);
    const QString &getName() const;
    void setName(const QString &newName);
    double getPurchase_price() const;
    void setPurchase_price(double newPurchase_price);
    double getSale_price() const;
    void setSale_price(double newSale_price);
    int getStock() const;
    void setStock(int newStock);
    const QString &getPurchase_date() const;
    void setPurchase_date(const QString &newPurchase_date);
    const QString &getSaller() const;
    void setSaller(const QString &newSaller);

    QString toString();
};
















#endif // ENTITY_H
