#include "database.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QDateTime>
#include <exception>
#include "QMessageBox"
database::database(QObject *parent) : QObject(parent)
{


    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");   //数据库驱动类型为SQL Server
       qDebug()<<"ODBC driver?"<<db.isValid();
       QString dsn = QString::fromLocal8Bit("ljq");      //数据源名称
       db.setHostName("localhost");                        //选择本地主机，127.0.1.1
       db.setDatabaseName(dsn);                            //设置数据源名称
       db.setUserName("ljq");                               //登录用户
       db.setPassword("123456");                              //密码
       if(!db.open())                                      //打开数据库
       {
           qDebug()<<db.lastError().text();
           QMessageBox::critical(0, QObject::tr("Database error"), db.lastError().text());
                                              //打开失败
       }
        else
       {
           QMessageBox::about(NULL,"提示","打开成功");
       }
    //QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","smart-home-db");
    //db.setDatabaseName("C:/Users/12234/Documents/build-secret_transfer-Desktop_Qt_6_0_4_MinGW_64_bit-Debug/qtDb.db");
 //  db.setDatabaseName("./qtDb.db");
 //   qDebug()<<db.databaseName();
  //  qDebug()<<db.driverName();
   // bool ok = db.open(); //打开数据库
   // if(!ok){
    //   qDebug() << "Fail to open database,error:" ;/*<< db.lastError.text();*/
    //   QMessageBox::about(NULL,"提示","数据库远程连接失败！");
   // } //检测输出
   // db.close();

}
database* database::userDb = NULL;

database *database::getdatabase()
{
    if(!userDb){
        userDb = new database;
    } //new一个构造函数

    return userDb;
}
bool database::addRegiserUser(const QString &username, const QString &password, const QString &email)
{
    //调用QSqlDatabase的静态函数databas创建了一个名为smart-home-db的连接
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");

    //创建一个关联的QSqlQuery对象，由QSqlQuery来实现以下工作
    QSqlQuery  query(db);

    //将输入username、password、email 的数据插入表中；
    query.prepare("INSERT INTO User1 (username,password,email) "
                  "VALUES (?, ?, ?)");

    query.addBindValue(username);
    query.addBindValue(password);
    query.addBindValue(email);
    qDebug()<<username<<" "<<password<<" "<<email;
    bool ok = query.exec(); //判断操作是否成功；
    if(!ok){
        qDebug() << "Fail add regiser user : " << query.lastError().text();
    }
    db.close();
    return ok;

}
bool database::addRegiserUser_Saleuser(const QString &username, const QString &password, const QString &email)
{
    //调用QSqlDatabase的静态函数databas创建了一个名为smart-home-db的连接
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");

    //创建一个关联的QSqlQuery对象，由QSqlQuery来实现以下工作
    QSqlQuery  query(db);
    QString str = QString("insert into Sale_user values(%1,%2,'%3')").arg(username).arg(password).arg(email);
    //将输入username、password、email 的数据插入表中；

    /*
    query.prepare("INSERT INTO Sale_user (username,password,email) "
                  "VALUES (?, ?, ?)");
    //insert into Sale_user values(3,3,'1223419806@qq.com')
    query.addBindValue(username);
    query.addBindValue(password);
    query.addBindValue(email);
    qDebug()<<username<<" "<<password<<" "<<email;
    bool ok = query.exec(); //判断操作是否成功；
    if(!ok){
        qDebug() << "Fail add regiser Sale_user : " << query.lastError().text();
        //qDebug()<<
    }

    */
    if(!query.exec(str))
    {
        qDebug()<<"error!" ;
    }
    else
    {
        qDebug()<<"success";
    }
    if(query.next()){
        return true;
    }
    else{
        return false;
    }
    db.close();
    //return ok;

}
//登陆的邮箱检测
bool database::database::queryemail(const QString &email)
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);

    //判断数据库中是否存在所输入邮箱
    query.prepare("select *from User1 where email=?");
    query.addBindValue(email);
    bool ok = query.exec();
    if(!ok){
        qDebug() << "Fail query register email" << db.lastError().text();
        return false;
    }
    if(query.next()){
        return true;
    }
    else{
        return false;
    }
    db.close();
}
bool database::database::queryemail_Saleuser(const QString &email)
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);

    //判断数据库中是否存在所输入邮箱
    QString str = QString("select *from Sale_user where email=%1").arg(email);
    /*query.prepare("select *from Sale_user where email=?");
    query.addBindValue(email);
    bool ok = query.exec();
    if(!ok){
        qDebug() << "Fail query register email" << db.lastError().text();
        return false;
    }
    if(query.next()){
        return true;
    }
    else{
        return false;
    }*/
    if(!query.exec(str))
    {
        qDebug()<<"error!" ;
    }
    else
    {
        qDebug()<<"success";
    }
    if(query.next()){
        return true;
    }
    else{
        return false;
    }
    db.close();
}
//登陆的用户名检测
bool database::database::queryusername(const QString &username)
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    query.prepare("select *from User1 where username=?");
    query.addBindValue(username);
    bool ok = query.exec();
    if(!ok){
        qDebug() << "Fail query register username" << db.lastError().text();
        return false;
    }
    if(query.next()){
        return true;
    }
    else{
        return false;
    }
    db.close();
}
bool database::database::queryusername_Saleuser(const QString &username)
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    QString str= QString("select *from Sale_user where User_name='%1'").arg(username);
    /*query.prepare("select *from Sale_user where User_name=?");
    query.addBindValue(username);
    bool ok = query.exec();
    if(!ok){
        qDebug() << "Fail query register username" << db.lastError().text();
        return false;
    }

    */
     qDebug()<<str;
    if(!query.exec(str))
    {
        qDebug()<<"error!" ;
    }
    else
    {
        qDebug()<<"success";
       // return 1;
    }
   // qDebug()<<query.value(0);
   if(query.next())
   {
        return true;
    }
    else
   {
        return false;
    }

    db.close();
}

//登陆的密码检测
bool database::database::querypassword(const QString &username,const QString &password)
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    QString str = QString("select *from User1 where username=%1 and password=%2").arg(username).arg(password);
   /* query.prepare("select *from User where User_name=? and password=?");
    query.addBindValue(username);
    query.addBindValue(password);
    bool ok = query.exec();
    if(!ok){
        qDebug() << "Fail query register password" << db.lastError().text();
        return false;
    }

    if(query.next()){
        return true;
    }
    else{
        return false;
    }*/
    qDebug()<<str;
    if(!query.exec(str))
    {
        qDebug()<<"error!" ;db.close();
        return 0;

    }
    else
    {
        qDebug()<<"success";db.close();
        return 1;
    }
    return 1;

}
bool database::database::querypassword_Saleuser(const QString &username,const QString &password)
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    QString str = QString("select *from Sale_user where User_name='%1' and password='%2'").arg(username).arg(password);
    //query.prepare("select *from Sale_user where User_name=? and password=?");
   // query.addBindValue(username);
    //query.addBindValue(password);
    qDebug()<<str;
    if(!query.exec(str))
    {
        qDebug()<<"error!" ;db.close();
        return 0;

    }
    else
    {
        qDebug()<<"success";db.close();
        return 1;
    }
}
bool database::database::findpassword(const QString &username,const QString &email)
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    query.prepare("select *from User1 where username=? and email=?");
    query.addBindValue(username);
    query.addBindValue(email);
    bool ok = query.exec();
    if(!ok){
        qDebug() << "Fail query register password" << db.lastError().text();
        return false;
    }
    if(query.next()){
        return true;
    }
    else{
        return false;
    }
    db.close();
}
bool database::database::update_password(const QString &username,const QString &password)
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    query.prepare("update User1 set password =? where username=?");
    query.addBindValue(password);
    query.addBindValue(username);

    bool ok = query.exec();
    if(!ok){
        qDebug() << "Fail query register password" << db.lastError().text();
        return false;
    }
    if(query.next()){
        return true;
    }
    else{
        return false;
    }
    db.close();
}
int database::database::get_now_number(QString tableName)
{
    int count = 0;
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    QString queryString=QString("SELECT count(*) FROM %1").arg(tableName);
    query.exec(queryString);

    query.next();
    count = query.value(0).toInt();
    db.close();
    return count;

}

bool database::database::deleteGoodsByGid(const int gid) {
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    QString queryString=QString("delete from goods_manage where gid = %1").arg(gid);
    return query.exec(queryString);
}
QStringList* database::database::getGoodsByGid(int id)
{

    //select * from goods_manage where gid = id
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    query.prepare("select * from goods_manage where gid = ?");
    query.addBindValue(id);
    bool ok = query.exec();
    if(!ok) {
        throw  new std::exception();
    }
    QStringList* list = new QStringList();

    if(query.first()){
    list->append(query.value("gid").toString());
    list->append(query.value("name").toString());
    list->append(query.value("purchase_prise").toString());
    list->append(query.value("sale_prise").toString());
    list->append(query.value("stock").toString());
    list->append(query.value("purchase_date").toString());
    list->append(query.value("purchaser").toString());
    list->append(query.value("phone").toString());
}

    db.close();
    return list;

}
//向数据库指定行插入数据
bool database::database::update_info(Goods* goods)
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    query.prepare("update goods_manage set name =?, purchase_prise =?, sale_prise =?, stock =?, purchase_date =?, purchaser =?, phone =? where gid=?");
    query.addBindValue(goods->getName());
    query.addBindValue(goods->getPurchase_price());
    query.addBindValue(goods->getSale_price());
    query.addBindValue(goods->getStock());
    query.addBindValue(goods->getPurchase_date());
    query.addBindValue(goods->getPurchaser());
    query.addBindValue(goods->getPhone());
    query.addBindValue(goods->getGid());

    bool ok = query.exec();
    if(!ok){
        qDebug() << "Fail query register password" << db.lastError().text();
        db.close();
        return false;
    }
    if(query.next()){
        db.close();
        return true;
    }
    else{
        db.close();
        qDebug()<<db.lastError();
        return false;

    }

}


bool database::database::add_good(QString name,QString purchase_prise,QString sale_prise,QString stock,QString purchase_date,QString purchaser,QString phone )
{

    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);

    //判断数据库中是否存在所输入邮箱
    query.prepare("insert into goods_manage(name,purchase_prise,sale_prise,stock,purchase_date,purchaser,phone) values(?,?,?,?,?,?,?)");
    query.addBindValue(name);
    query.addBindValue(purchase_prise);
    query.addBindValue(sale_prise);
    query.addBindValue(stock);
    query.addBindValue(purchase_date);
    query.addBindValue(purchaser);
    query.addBindValue(phone);
    bool ok = query.exec();
    if(!ok){
        qDebug() << "Fail insert goods" << db.lastError().text();
        db.close();
        return false;
    }qDebug()<<"2222222";
    if(query.next()){
        db.close();
        return true;
    }
    else{
        db.close();
        return false;
    }
}
int database::database::ask_num(QString name)
{
    //select sum(stock) from goods_manage where name = ?
    int count = 0;
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
 //   QString queryString=QString("select sum(stock) from goods_manage where name = ?");
    QString queryString=QString("select sum(stock) from goods_manage where name = '%1'").arg(name);
 //   query.addBindValue(name);
    if(!query.exec(queryString))
    {
        qDebug()<<"error!" << name;
    }

    qDebug()<<queryString;
    //if(query.next())
    if(query.next())
    {
    count = query.value(0).toInt();
    qDebug()<<count;
    }
    qDebug()<<query.lastError();
    db.close();
    return count;

}
bool database::database::add_to_salemanage(QString name,QString purchase_prise,QString sale_prise,QString stock,int gid)
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);

    //判断数据库中是否存在所输入邮箱
    query.prepare("insert into order_history(goods_name,purchase_price,sale_price,stock,gid) values(?,?,?,?,?)");
    query.addBindValue(name);
    query.addBindValue(purchase_prise);
    query.addBindValue(sale_prise);
    query.addBindValue(stock);
    query.addBindValue(gid);
    bool ok = query.exec();
    if(!ok){
        qDebug() << "Fail insert goods to sale" << db.lastError().text();
        db.close();
        return false;
    }
    if(query.next()){
        db.close();
        return true;
    }
    else{
        db.close();
        return false;
    }
}
QStringList* database::database::getGidsByName(QString name)
{
    //select gid from goods_manage where name = ? order by purchase_date
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);


    query.prepare("select gid from goods_manage where name = ? order by purchase_date");
    query.addBindValue(name);
    bool ok = query.exec();
    QStringList* list = new QStringList();
    list->append(query.value("gid").toString());

    qDebug() << (*list);
    qDebug()<<query.lastError();
    qDebug()<<query.value("gid");

    if(!ok){
        qDebug() << "Fail return goods id" << db.lastError().text();
        db.close();
        return NULL;
    }
    while(query.next()){
        //qDebug()<<query.lastError();qDebug()<<query.value("gid");
        list->append(query.value("gid").toString());
        qDebug()<<query.value("gid");
        //db.close();
        //return true;
    }
   // else{
        db.close();
     //   return false;
 //   }
    qDebug() << (*list);
    return list;
}

int database::database::getStockByGid(int gid)
{
    int count = 0;
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    QString queryString=QString("select stock from goods_manage where gid = %1").arg(gid);
    if(!query.exec(queryString))
    {
        qDebug()<<"error!" << gid;
    }

    qDebug()<<queryString;
    if(query.next())
    {
    count = query.value(0).toInt();
    qDebug()<<count;
    }
    qDebug()<<query.lastError();
    db.close();
    return count;

}

bool database::database::subStockByGid(int gid, int count) {
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);

    query.prepare("update goods_manage set stock = ? where gid = ?");
    query.addBindValue(count);
    query.addBindValue(gid);
    bool ok = query.exec();
    if(!ok) {
        qDebug() <<query.lastError()<<"error!!";

    }
    return true;
}

bool database::insertIntoOrder(Order *order)
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);

    query.prepare("insert into order_history(goods_name, goods_num, buyer, address1, phone, order_date, gid) \
                    values(?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(order->getGoods_name());
    query.addBindValue(order->getGoods_num());
    query.addBindValue(order->getBuyer());
    query.addBindValue(order->getAddress());
    query.addBindValue(order->getPhone());
    query.addBindValue(order->getOrder_date());
    query.addBindValue(order->getGid());
    bool succeed = query.exec();
    db.close();
    return succeed;
}

int database::getGoods_numByGoods_name(QString Goods_name)
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    query.prepare("select sum(goods_num) sum from order_history where goods_name = ?");
    query.addBindValue(Goods_name);
    if(!query.exec()) {
        //TODO
        db.close();

    }
    //把query执行后获取的数据以int形式返回
    else if(query.next())
    {
        db.close();
        return query.value("sum").toInt();
    }
    return -1;
}

QVector<int> *database::getSalesPerMonthByName(QString &name)
{
    QVector<int>* nums = new QVector<int>();
    QDateTime current_date_time =QDateTime::currentDateTime();
    int year = current_date_time.toString("yyyy").toInt();
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);

    for(int i = 1; i <= 12; i++) {
        QString temp = QString("'%1.%2%3%'").arg(year).arg(i < 10 ? "0" : "").arg(i);
        QString str = QString("select sum(goods_num) sum from order_history where goods_name = %1 and order_date like %2").arg(name).arg(temp);
        qDebug()<<str;
        query.prepare(str);
        if(!query.exec()) {
            qDebug()<<query.lastError();
        }
        //获取sum
        if(query.next())
        {
            nums->append(query.value("sum").toInt());
            qDebug()<<nums->value(i);
        }
    }

    db.close();
    return nums;
}
bool database::database::delete_sale_history(const int oid) {
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    QString queryString=QString("delete from order_history where oid = %1").arg(oid);
    bool succeed = query.exec(queryString);
    db.close();
    return succeed;
}

QStringList database::selectAllFromOrder()
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    QString queryString=QString("select distinct buyer from order_history");
    bool succeed = query.exec(queryString);
    if(!succeed) {
        qDebug() << "get error";
        exit(1);
    }
    QStringList list;
    while(query.next()) {
        list.append(query.value("buyer").toString());
    }
    db.close();
    return list;
}

QString database::getAddressByBuyer(QString buyer)
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QString result("");
    QSqlQuery query(db);
    query.prepare("select address1 from order_history where buyer = ? order by order_date desc limit 0,1");
    query.addBindValue(buyer);
    bool succeed = query.exec();
    if(!succeed) {
        qDebug() << "error in database.cpp.getAddressByBuyer(QString) QString @line 498";
        return result;
    }
    if(query.next()) {
        result = query.value("address1").toString();
    }
    db.close();
    return result;
}

QString database::getPhoneByBuyer(QString buyer)
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QString result("");
    QSqlQuery query(db);
    query.prepare("select phone from order_history where buyer = ? order by order_date desc limit 0,1");
    query.addBindValue(buyer);
    bool succeed = query.exec();
    if(!succeed) {
        qDebug() << "error in database.cpp.getAddressByBuyer(QString) QString @line 498";
        return result;
    }
    if(query.next()) {
        result = query.value("phone").toString();
    }
    db.close();
    return result;
}
bool database::create_messagebox(const QString &username)
{
    //调用QSqlDatabase的静态函数databas创建了一个名为smart-home-db的连接
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");

    QSqlQuery  query(db);


    QString str = QString("create table '%1'(info varchar , data varchar)").arg(username);


    return query.exec(str);
    db.close();

}
QList<QString> database::get_friends_info()
{
    QList<QString>* info = new QList<QString>();
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);

    QString str = QString("select User_name from Sale_user ");
    if(!query.exec(str)){
        qDebug() << "Fail return User_name" << db.lastError().text();
        db.close();

    }
    while(query.next()){

        info->append(query.value("User_name").toString());
        qDebug()<<query.value("User_name");
        //db.close();
        //return true;
    }
    db.close();
    return *info;
}
bool database::write_into_messagebox(QString message,QString name)
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");

    QSqlQuery  query(db);
    //insert into [3] values('qqqqqq',getdate(),'1')
    QString str1 = QString("insert into [%1] values('%2',getdate(),'1')").arg(name).arg(message);
   // QString str2 = QString("insert into '%1'(data) values(datetime())").arg(message);
    //insert into '3' values('123456',datetime())
    if(!query.exec(str1))
    {
        qDebug()<<"error!" ;
        return 0;
    }

    qDebug()<<str1;
    return 1;

    db.close();
}
QVector<int> database::judge_sale_or_user(QString name)
{

    QVector<int> *info = new QVector<int>();
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");

    QSqlQuery  query(db);
    //select saleuser_or_user from '3' where data = '2021-10-16 13:41:31'
    //select saleuser_or_user from '3'
    QString str = QString("select saleuser_or_user from [%1]").arg(name);
    if(!query.exec(str)){
        qDebug() << "Fail return judge" << db.lastError().text();
        db.close();

    }
    while(query.next()){

        info->append(query.value("saleuser_or_user").toInt());
        qDebug()<<query.value("saleuser_or_user");
        //db.close();
        //return true;
    }
    db.close();
    return *info;
}
QList<QString> database::get_friends_message(QString name)
{
    QList<QString>* info = new QList<QString>();
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);

    QString str = QString("select info from [%1] ").arg(name);
    if(!query.exec(str)){
        qDebug() << "Fail return message" << db.lastError().text();
        db.close();

    }
    while(query.next()){

        info->append(query.value("info").toString());
        qDebug()<<query.value("info");
        //db.close();
        //return true;
    }
    db.close();
    return *info;
}
bool database::support_write_into_messagebox(QString message,QString name)
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");

    QSqlQuery  query(db);
     //insert into [3] values('qqqqqq',getdate(),'1')
    QString str1 = QString("insert into [%1] values('%2',getdate(),'0')").arg(name).arg(message);
   // QString str2 = QString("insert into '%1'(data) values(datetime())").arg(message);
    //insert into '3' values('123456',datetime())
    if(!query.exec(str1))
    {
        qDebug()<<"error!" ;
        return 0;
    }

    qDebug()<<str1;
    return 1;

    db.close();
}
bool database::del_support(QString name)
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");

    QSqlQuery  query(db);
    //delete from Sale_user where User_name = '6'
    QString str1 = QString("delete from Sale_user where User_name = '%1'").arg(name);
    if(!query.exec(str1))
    {
        qDebug()<<"error!" ;db.close();
        return 0;
    }

    qDebug()<<str1;db.close();
    return 1;

    //db.close();
}
bool database::database::add_cargo(QString name,QString purchase_prise,QString sale_prise,QString stock,QString purchase_date, QString seller )
{

    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);

    //判断数据库中是否存在所输入邮箱
    query.prepare("insert into cargo_manage(name,purchase_price,sale_price,stock,purchase_date,seller) values(?,?,?,?,?,?)");
    query.addBindValue(name);
    query.addBindValue(purchase_prise);
    query.addBindValue(sale_prise);
    query.addBindValue(stock);
    query.addBindValue(purchase_date);
    query.addBindValue(seller);
    bool ok = query.exec();
    if(!ok){
        qDebug() << "Fail insert goods" << db.lastError().text();
        db.close();
        return false;
    }qDebug()<<"2222222";
    if(query.next()){
        db.close();
        return true;
    }
    else{
        db.close();
        return false;
    }
}
bool database::database::delete_cargo_ByGid(const int gid) {
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    QString queryString=QString("delete from cargo_manage where gid = %1").arg(gid);
    return query.exec(queryString);
}
int database::database::ask_cargo_num(QString name)
{
    //select sum(stock) from goods_manage where name = ?
    int count = 0;
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
 //   QString queryString=QString("select sum(stock) from cargo_manage where name = ?");
    QString queryString=QString("select sum(stock) from cargo_manage where name = '%1'").arg(name);
 //   query.addBindValue(name);
    if(!query.exec(queryString))
    {
        qDebug()<<"error!" << name;
    }

    qDebug()<<queryString;
    //if(query.next())
    if(query.next())
    {
    count = query.value(0).toInt();
    qDebug()<<count;
    }
    qDebug()<<query.lastError();
    db.close();
    return count;

}
bool database::database::update_cargo_info(Cargo* cargo)
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    QString str = QString("update cargo_manage set name ='%1', purchase_price = %2, sale_price =%3, stock =%4, purchase_date ='%5' where gid='%6'"
).arg(cargo->getName()).arg(QString::number(cargo->getPurchase_price())).arg(QString::number(cargo->getSale_price())).arg(QString::number(cargo->getStock())).arg(cargo->getPurchase_date()).arg(QString::number(cargo->getGid()));
   // query.prepare("update cargo_manage set name =?, purchase_price =?, sale_price =?, stock =?, purchase_date =? where gid=?");
   /*
    query.addBindValue(cargo->getName());
    query.addBindValue(cargo->getPurchase_price());
    query.addBindValue(cargo->getSale_price());
    query.addBindValue(cargo->getStock());
    query.addBindValue(cargo->getPurchase_date());
    query.addBindValue(cargo->getGid());
  //  qDebug()<<cargo->getName()
    bool ok = query.exec();
    if(!ok){
        qDebug() << "Fail update cargo!!!!!!!!!!!!" << db.lastError().text();
        db.close();
        return false;
    }
    */
   /* if(query.next()){
        db.close();
        return true;
    }
    else{
        db.close();
        qDebug()<<db.lastError();
        return false;

    }

    qDebug()<<"0000000000000!";
    return 1;*/
    if(!query.exec(str))
    {
        qDebug()<<"error!" ;
        return 0;
    }

    qDebug()<<str;
    return 1;

    db.close();


}
int database::database::get_cargo_GidsByName(QString name)
{
    //select gid from goods_manage where name = ? order by purchase_date
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);


    query.prepare("select gid from cargo_manage where name = ?");
    query.addBindValue(name);
    bool ok = query.exec();
    int gid = 0;

    qDebug()<<query.lastError();
    qDebug()<<query.value("gid");

    if(!ok){
        qDebug() << "Fail return cargo id" << db.lastError().text();
        db.close();
        return NULL;
    }
    if(query.next()){
        gid = query.value("gid").toInt();
        qDebug()<<query.value("gid");
    }
    db.close();
    return gid;
}

int database::database::get_cargo_StockByGid(int gid)
{
    int count = 0;
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    QString queryString=QString("select stock from cargo_manage where gid = %1").arg(gid);
    if(!query.exec(queryString))
    {
        qDebug()<<"error!" << gid;
    }

    qDebug()<<queryString;
    if(query.next())
    {
    count = query.value(0).toInt();
    qDebug()<<count;
    }
    qDebug()<<query.lastError();
    db.close();
    return count;
}

bool database::modifyStockByGid(int gid, int stock)
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    QString queryString=QString("update cargo_manage set stock = %1 where gid = %2").arg(gid).arg(stock);
    if(!query.exec(queryString))
    {
        qDebug()<<"error!" << gid;
        db.close();
        return 0;
    }
    db.close();
    return 1;
}

Cargo *database::getCargoByGid(int gid)
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    QString queryString=QString("select name, purchase_price, sale_price, stock, purchase_date from cargo_manage where gid = %1").arg(gid);
    if(!query.exec(queryString))
    {
        qDebug()<<"error int database::getCargoByGid(int)" << gid;
        db.close();
        return NULL;
    }
    if(!query.next()) {
        db.close();
        return NULL;
    }
    Cargo* cargo = new Cargo(
                query.value("name").toString(),
                query.value("purchase_price").toDouble(),
                query.value("sale_price").toDouble(),
                query.value("stock").toInt(),
                query.value("purchase_date").toString()
                );
    return cargo;
}
