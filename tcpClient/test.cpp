#include "client.h"
#include "cOperation.h"
#include <iostream>
#include <Windows.h>
#include <json/json.h>
#include <fstream>
#include <cstring>

#include <thread>
#include <future>

using namespace std;
using namespace Json;

void hanshu(std::string strValue, string& token)
{
    Client client;
    client.sendData(strValue);
    token = client.recvData();
}

void myTime(std::string strValue)
{
    Client client;
    client.sendData(strValue);
    client.recvData();
}

std::string createString2()
{
    Json::Value root;
    Json::Value person;

    StreamWriterBuilder writerBuilder; // ��ʽAPI
    ostringstream os;
    writerBuilder.settings_["emitUTF8"] = true;

    //root.append(userArray);
    person["loginName"] = "T2021";
    person["password"] = encryptMd5("34vs");

    root["userArray"].append(person);
    root["function"] = "login";

    // ����ʹ������ָ��
    unique_ptr<StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
    jsonWriter->write(root, &os); // json-->stringstream
    string data = os.str(); // תΪstring

    // ����Json�ַ���
    //string strValue = root.toStyledString();      // json����ת��Ϊjson�ַ���
    return data;
}

std::string createString1()
{
    Json::Value root;
    Json::Value person;

    StreamWriterBuilder writerBuilder; // ��ʽAPI
    ostringstream os;

    //root.append(userArray);
    person["loginName"] = "T2022";
    person["password"] = ("3979f7f001b2962787ccc75f394b7689");
    //person["sex"] = "male";
    root["userArray"].append(person);
    root["function"] = "login";
    writerBuilder.settings_["emitUTF8"] = true;

    // ����ʹ������ָ��
    unique_ptr<StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
    jsonWriter->write(root, &os); // json-->stringstream
    string data = os.str(); // תΪstring

    //cout << data << endl;

    return data;
}

std::string createString3()
{
    Json::Value root;
    Json::Value person;

    StreamWriterBuilder writerBuilder; // ��ʽAPI
    ostringstream os;
    writerBuilder.settings_["emitUTF8"] = true;

    //root.append(userArray);
    person["loginName"] = "T2023";
    person["password"] = encryptMd5("test");
    //person["sex"] = "male";
    root["userArray"].append(person);
    root["function"] = "login";

    // ����ʹ������ָ��
    unique_ptr<StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
    jsonWriter->write(root, &os); // json-->stringstream
    string data = os.str(); // תΪstring

    cout << data << endl;

    return data;
}

std::string createStringTimeTable1(string token)
{
    Json::Value root;
    Json::Value timeTable;

    StreamWriterBuilder writerBuilder; // ��ʽAPI
    ostringstream os;
    writerBuilder.settings_["emitUTF8"] = true;

    //root.append(userArray);
    root["function"] = "updateTimeTable";
    timeTable["projectName"] = "del";
    timeTable["duration"] = "10";
    timeTable["myDate"] = "2020-1-1";
    root["projects"].append(timeTable);
    timeTable["projectName"] = "io";
    timeTable["duration"] = "10";
    timeTable["myDate"] = "2020-1-1";
    root["projects"].append(timeTable);
    root["token"] = token;

    // ����ʹ������ָ��
    unique_ptr<StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
    jsonWriter->write(root, &os); // json-->stringstream
    string data = os.str(); // תΪstring

    return data;
}

std::string createStringTimeTable2(string token)
{
    Json::Value root;
    Json::Value timeTable;

    StreamWriterBuilder writerBuilder; // ��ʽAPI
    ostringstream os;
    writerBuilder.settings_["emitUTF8"] = true;

    //root.append(userArray);
    root["function"] = "updateTimeTable";
    timeTable["projectName"] = "del";
    timeTable["duration"] = "66";
    timeTable["myDate"] = "2020-1-1";
    root["projects"].append(timeTable);
    timeTable["projectName"] = "io";
    timeTable["duration"] = "66";
    timeTable["myDate"] = "2020-1-1";
    root["projects"].append(timeTable);
    root["token"] = token;

    // ����ʹ������ָ��
    unique_ptr<StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
    jsonWriter->write(root, &os); // json-->stringstream
    string data = os.str(); // תΪstring

    return data;
}

std::string createStringTimeTable3(string token)
{
    Json::Value root;
    Json::Value timeTable;

    StreamWriterBuilder writerBuilder; // ��ʽAPI
    ostringstream os;
    writerBuilder.settings_["emitUTF8"] = true;

    //root.append(userArray);
    root["function"] = "updateTimeTable";
    timeTable["projectName"] = "del";
    timeTable["duration"] = "3";
    timeTable["myDate"] = "2020-1-1";
    root["projects"].append(timeTable);
    timeTable["projectName"] = "io";
    timeTable["duration"] = "4";
    timeTable["myDate"] = "2020-1-1";
    root["projects"].append(timeTable);
    root["token"] = token;

    // ����ʹ������ָ��
    unique_ptr<StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
    jsonWriter->write(root, &os); // json-->stringstream
    string data = os.str(); // תΪstring

    return data;
}




int main()
{
    std::string token1;

    string strValue1 = createString1();
    thread thread1(hanshu, strValue1, ref(token1));
    thread1.join();

    std::vector<std::string> vtoken1 = split(token1, ",");
    token1 = vtoken1[0];

    //Group�����������Գɹ�

    /*strValue1 = getGroup(token1);
    thread thread4(myTime, strValue1);
    thread4.join();

    strValue1 = insertGroup(token1, "testing");
    thread thread5(myTime, strValue1);
    thread5.join();

    std::vector<std::string> newGroupName;
    std::vector<std::string> oldGroupName;
    newGroupName.emplace_back("test");
    newGroupName.emplace_back("io");
    oldGroupName.emplace_back("testing");
    oldGroupName.emplace_back("1");

    strValue1 = updateGroup(token1, newGroupName, oldGroupName);
    thread thread6(myTime, strValue1);
    thread6.join();*/

    //User�����������Գɹ�

    /*strValue1 = getUser(token1);
    thread thread4(myTime, strValue1);
    thread4.join();

    strValue1 = insertUser(token1, "T2024", "����", "�Ƴ�", "����", "0");
    thread thread5(myTime, strValue1);
    thread5.join();
    
    std::vector<std::string> userName;
    std::vector<std::string> authority;
    userName.emplace_back("red");
    userName.emplace_back("�Ƴ�");
    authority.emplace_back("1");
    authority.emplace_back("2");

    strValue1 = updateUserAuthority(token1, userName, authority);
    thread thread6(myTime, strValue1);
    thread6.join();*/

    //Project�����������Գɹ�

    /*strValue1 = getProject(token1);
    thread thread4(myTime, strValue1);
    thread4.join();

    strValue1 = insertProject(token1, "testing", "test", "�����");
    thread thread5(myTime, strValue1);
    thread5.join();

    std::vector<std::string> newProjectName;
    std::vector<std::string> oldProjectName;
    std::vector<std::string> manager;
    std::vector<std::string> state;
    newProjectName.emplace_back("del");
    newProjectName.emplace_back("io");
    oldProjectName.emplace_back("del");
    oldProjectName.emplace_back("io");
    manager.emplace_back("��־");
    manager.emplace_back("�Ƴ�");
    state.emplace_back("���");
    state.emplace_back("���");

    strValue1 = updateProject(token1, newProjectName, oldProjectName, manager, state);
    thread thread6(myTime, strValue1);
    thread6.join();*/

    //TimeTable�����������Գɹ�

    ////���Գɹ�,������ȷ��ȡʱ���
    //strValue1 = getTimeTable(token1,"2020-1-1","2020-1-2","user","not counted");
    //thread thread4(myTime, strValue1);
    //thread4.join();

    ////���Գɹ�,�������ݾ�ʧ�ܣ�û�оͳɹ�����
    //strValue1 = insertTimeTable(token1, "2020-1-2", "del", "5");
    //thread thread5(myTime, strValue1);
    //thread5.join();

    ////���Գɹ�,�ɹ�����
    //std::vector<std::string> userName;
    //std::vector<std::string> projectName;
    //std::vector<std::string> duration;
    //userName.emplace_back("yellow");
    //userName.emplace_back("yellow");
    //projectName.emplace_back("del");
    //projectName.emplace_back("io");
    //duration.emplace_back("3");
    //duration.emplace_back("3");

    //strValue1 = updateTimeTable(token1, "2020-1-1", userName, projectName, duration);
    //thread thread6(myTime, strValue1);
    //thread6.join();

	return 0;
}