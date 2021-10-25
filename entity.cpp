#include "entity.h"

Entity::Entity()
{

}

QString Entity::toString()
{
    return NULL;
}

int Goods::getGid() const
{
    return gid;
}

const QString &Goods::getName() const
{
    return name;
}

void Goods::setName(const QString &newName)
{
    name = newName;
}

double Goods::getPurchase_price() const
{
    return purchase_price;
}

void Goods::setPurchase_price(double newPurchase_price)
{
    purchase_price = newPurchase_price;
}

double Goods::getSale_price() const
{
    return sale_price;
}

void Goods::setSale_price(double newSale_price)
{
    sale_price = newSale_price;
}

int Goods::getStock() const
{
    return stock;
}

void Goods::setStock(int newStock)
{
    stock = newStock;
}

const QString &Goods::getPurchase_date() const
{
    return purchase_date;
}

void Goods::setPurchase_date(const QString &newPurchase_date)
{
    purchase_date = newPurchase_date;
}

const QString &Goods::getPurchaser() const
{
    return purchaser;
}

void Goods::setPurchaser(const QString &newPurchaser)
{
    purchaser = newPurchaser;
}

const QString &Goods::getPhone() const
{
    return phone;
}

void Goods::setPhone(const QString &newPhone)
{
    phone = newPhone;
}

Goods::Goods(int gid, const QString &name, double purchase_price, double sale_price, int stock, const QString &purchase_date, const QString &purchaser, const QString &phone) : gid(gid),
    name(name),
    purchase_price(purchase_price),
    sale_price(sale_price),
    stock(stock),
    purchase_date(purchase_date),
    purchaser(purchaser),
    phone(phone)
{}

int Order::getOid() const
{
    return oid;
}

const QString &Order::getGoods_name() const
{
    return goods_name;
}

void Order::setGoods_name(const QString &newGoods_name)
{
    goods_name = newGoods_name;
}

int Order::getGoods_num() const
{
    return goods_num;
}

void Order::setGoods_num(int newGoods_num)
{
    goods_num = newGoods_num;
}

const QString &Order::getBuyer() const
{
    return buyer;
}

void Order::setBuyer(const QString &newBuyer)
{
    buyer = newBuyer;
}

const QString &Order::getAddress() const
{
    return address;
}

void Order::setAddress(const QString &newAddress)
{
    address = newAddress;
}

const QString &Order::getPhone() const
{
    return phone;
}

void Order::setPhone(const QString &newPhone)
{
    phone = newPhone;
}

const QString &Order::getOrder_date() const
{
    return order_date;
}

void Order::setOrder_date(const QString &newOrder_date)
{
    order_date = newOrder_date;
}

Order::Order(int oid, const QString &goods_name, int goods_num, const QString &buyer, const QString &address, const QString &phone, const QString &order_date, int gid) : oid(oid),
    goods_name(goods_name),
    goods_num(goods_num),
    buyer(buyer),
    address(address),
    phone(phone),
    order_date(order_date),
    gid(gid)
{}

int Order::getGid() const
{
    return gid;
}

void Order::setGid(int newGid)
{
    gid = newGid;
}

Order::Order(const QString &goods_name, int goods_num, const QString &buyer, const QString &address, const QString &phone, const QString &order_date, int gid) : goods_name(goods_name),
    goods_num(goods_num),
    buyer(buyer),
    address(address),
    phone(phone),
    order_date(order_date),
    gid(gid)
{}

const QString &Pair::getName() const
{
    return name;
}

void Pair::setName(const QString &newName)
{
    name = newName;
}

int Pair::getSum() const
{
    return sum;
}

void Pair::setSum(int newSum)
{
    sum = newSum;
}

bool Pair::operator>(Pair &p)
{
    return this->sum > p.sum;
}

bool Pair::operator<(Pair &p)
{
    return this->sum < p.sum;
}

bool Pair::operator==(Pair &p)
{
    return this->sum == p.sum;
}

Pair::Pair(const QString &name, int sum) : name(name),
    sum(sum)
{}

int Cargo::getGid() const
{
    return gid;
}

void Cargo::setGid(int newGid)
{
    gid = newGid;
}

const QString &Cargo::getName() const
{
    return name;
}

void Cargo::setName(const QString &newName)
{
    name = newName;
}

double Cargo::getPurchase_price() const
{
    return purchase_price;
}

void Cargo::setPurchase_price(double newPurchase_price)
{
    purchase_price = newPurchase_price;
}

double Cargo::getSale_price() const
{
    return sale_price;
}

void Cargo::setSale_price(double newSale_price)
{
    sale_price = newSale_price;
}

int Cargo::getStock() const
{
    return stock;
}

void Cargo::setStock(int newStock)
{
    stock = newStock;
}

const QString &Cargo::getPurchase_date() const
{
    return purchase_date;
}

void Cargo::setPurchase_date(const QString &newPurchase_date)
{
    purchase_date = newPurchase_date;
}

const QString &Cargo::getSaller() const
{
    return saller;
}

void Cargo::setSaller(const QString &newSaller)
{
    saller = newSaller;
}

QString Cargo::toString()
{
    return "Cargo [gid=" + QString::number(this->gid) + ", name=" + this->name + ", purchase_price=" +
            QString::number(this->purchase_price) + ", sale_price=" + QString::number(this->sale_price) +
            ", stock=" + QString::number(this->stock) + ", purchase_date=" + this->purchase_date +
            ", saller=" + this->saller + "]";
}

Cargo::Cargo(int gid, const QString &name, double purchase_price, double sale_price, int stock, const QString &purchase_date, const QString &saller) : gid(gid),
    name(name),
    purchase_price(purchase_price),
    sale_price(sale_price),
    stock(stock),
    purchase_date(purchase_date),
    saller(saller)
{}

Cargo::Cargo(const QString &name, double purchase_price, double sale_price, int stock, const QString &purchase_date) : name(name),
    purchase_price(purchase_price),
    sale_price(sale_price),
    stock(stock),
    purchase_date(purchase_date)
{}
