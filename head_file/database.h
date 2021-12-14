#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include "Entity.h"
#include <QSqlDatabase>
#include "QSqlQuery"

//同时追踪的最大数量
#define TRACKING_MAX_NUM 15



class database : public QObject
{
    Q_OBJECT
public:
    static database *getdatabase();
    //函数声明
        bool addRegiserUser(const QString &username,const QString &password,const  QString &email);
        bool queryemail(const QString &email);
        bool queryusername(const QString &username);
        bool querypassword(const QString &username,const QString &password);
        bool findpassword(const QString &username,const QString &password);
        bool update_password(const QString &username,const QString &password);
        int get_now_number(QString tableName);
        bool deleteGoodsByGid(const int gid);
        bool update_info(Goods* goods);
        QStringList* getGoodsByGid(int id);
        bool add_good(QString name,QString purchase_price,QString sale_price,QString stock,QString purchase_date,QString purchaser,QString phone );
        int ask_num(QString name);
        bool add_to_salemanage(QString name,QString purchase_prise,QString sale_prise,QString stock, int gid);
        QStringList*  getGidsByName(QString name);
        int getStockByGid(int gid);
        bool subStockByGid(int gid, int count);
        bool insertIntoOrder(Order* order);
        int getGoods_numByGoods_name(QString Goods_name);
        QVector<int>* getSalesPerMonthByName(QString& name);
        bool delete_sale_history(const int oid) ;
        QStringList selectAllFromOrder();
        QString getAddressByBuyer(QString buyer);
        QString getPhoneByBuyer(QString buyer);
        bool addRegiserUser_Saleuser(const QString &username, const QString &password, const QString &email);
        bool queryemail_Saleuser(const QString &email);
        bool queryusername_Saleuser(const QString &username);
        bool querypassword_Saleuser(const QString &username,const QString &password);
        bool create_messagebox(const QString &username);
        QList<QString> get_friends_info();
        bool write_into_messagebox(QString message,QString name);
        QVector<int> judge_sale_or_user(QString name);
        QList<QString> get_friends_message(QString name);
        bool support_write_into_messagebox(QString message,QString name);
        bool del_support(QString name);
        bool add_cargo(QString name,QString purchase_prise,QString sale_prise,QString stock,QString purchase_date, QString seller );
        bool delete_cargo_ByGid(const int gid);
        int ask_cargo_num(QString name);
        bool update_cargo_info(Cargo* cargo);
        int get_cargo_GidsByName(QString name);
        int get_cargo_StockByGid(int gid);
        bool modifyStockByGid(int gid, int stock);
        Cargo* getCargoByGid(int gid);
        void close();


        const QSqlDatabase &getConnect() const;
        const QSqlQuery &getQuery() const;

signals:

public slots:

private: //构造函数私有化
    static database *userDb;
    QSqlDatabase connect;
    static bool has_connected;
    QSqlQuery query;

    explicit database(QObject *parent = nullptr);


};
#endif // DATABASE_H
