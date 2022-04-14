#ifndef COPERATION_H
#define COPERATION_H

#include <iostream>
#include <vector>
#include <cryptopp/cryptlib.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>
#include <cryptopp/files.h>
#include <cryptopp/hex.h>
#include <json/json.h>

using namespace CryptoPP;

//测试用例函数

std::string updateTimeTable(std::string token, std::string myDate, std::vector<std::string> userName, 
    std::vector<std::string> projectName, std::vector<std::string> duration)
{
    Json::Value root;
    Json::Value timeTable;

    Json::StreamWriterBuilder writerBuilder; // 新式API
    std::ostringstream os;
    writerBuilder.settings_["emitUTF8"] = true;

    root["function"] = "updateTimeTable";
    root["token"] = token;
    root["myDate"] = myDate;
    for (int i = 0; i < projectName.size(); i++)
    {
        timeTable["userName"] = userName[i];
        timeTable["projectName"] = projectName[i];
        timeTable["duration"] = duration[i];
        root["timeTable"].append(timeTable);
    }

    // 这里使用智能指针
    std::unique_ptr<Json::StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
    jsonWriter->write(root, &os); // json-->stringstream
    std::string data = os.str(); // 转为string

    return data;
}

std::string insertTimeTable(std::string token, std::string myDate, std::string projectName, std::string duration)
{
    Json::Value root;
    Json::Value timeTable;

    Json::StreamWriterBuilder writerBuilder; // 新式API
    std::ostringstream os;
    writerBuilder.settings_["emitUTF8"] = true;

    root["function"] = "insertTimeTable";
    root["token"] = token;
    root["myDate"] = myDate;
    timeTable["projectName"] = projectName;
    timeTable["duration"] = duration;
    root["timeTable"].append(timeTable);

    // 这里使用智能指针
    std::unique_ptr<Json::StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
    jsonWriter->write(root, &os); // json-->stringstream
    std::string data = os.str(); // 转为string

    return data;
}

std::string getTimeTable(std::string token, std::string startDate, std::string endDate, std::string range, std::string total)
{
    Json::Value root;
    Json::Value timeTable;

    Json::StreamWriterBuilder writerBuilder; // 新式API
    std::ostringstream os;
    writerBuilder.settings_["emitUTF8"] = true;

    root["function"] = "getTimeTable";
    root["token"] = token;
    timeTable["startDate"] = startDate;
    timeTable["endDate"] = endDate;
    timeTable["range"] = range;
    timeTable["total"] = total;
    root["timeTable"].append(timeTable);

    // 这里使用智能指针
    std::unique_ptr<Json::StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
    jsonWriter->write(root, &os); // json-->stringstream
    std::string data = os.str(); // 转为string

    return data;
}


std::string updateProject(std::string token, std::vector<std::string> newProjectName,
    std::vector<std::string> oldProjectName, std::vector<std::string> manager, std::vector<std::string> state)
{
    Json::Value root;
    Json::Value projects;

    Json::StreamWriterBuilder writerBuilder; // 新式API
    std::ostringstream os;
    writerBuilder.settings_["emitUTF8"] = true;

    root["function"] = "updateProject";
    root["token"] = token;
    for (int i = 0; i < newProjectName.size(); i++)
    {
        projects["newProjectName"] = newProjectName[i];
        projects["oldProjectName"] = oldProjectName[i];
        projects["manager"] = manager[i];
        projects["state"] = state[i];
        root["projects"].append(projects);
    }

    // 这里使用智能指针
    std::unique_ptr<Json::StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
    jsonWriter->write(root, &os); // json-->stringstream
    std::string data = os.str(); // 转为string

    return data;
}

std::string insertProject(std::string token, std::string projectName, std::string manager, std::string state)
{
    Json::Value root;
    Json::Value projects;

    Json::StreamWriterBuilder writerBuilder; // 新式API
    std::ostringstream os;
    writerBuilder.settings_["emitUTF8"] = true;

    root["function"] = "insertProject";
    root["token"] = token;
    projects["projectName"] = projectName;
    projects["manager"] = manager;
    projects["state"] = state;
    root["projects"].append(projects);

    // 这里使用智能指针
    std::unique_ptr<Json::StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
    jsonWriter->write(root, &os); // json-->stringstream
    std::string data = os.str(); // 转为string

    return data;
}

std::string getProject(std::string token)
{
    Json::Value root;
    Json::Value projects;

    Json::StreamWriterBuilder writerBuilder; // 新式API
    std::ostringstream os;
    writerBuilder.settings_["emitUTF8"] = true;

    root["function"] = "getProject";
    root["token"] = token;

    // 这里使用智能指针
    std::unique_ptr<Json::StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
    jsonWriter->write(root, &os); // json-->stringstream
    std::string data = os.str(); // 转为string

    return data;
}


std::string updateUserAuthority(std::string token, std::vector<std::string> userName, std::vector<std::string> authority)
{
    Json::Value root;
    Json::Value user;

    Json::StreamWriterBuilder writerBuilder; // 新式API
    std::ostringstream os;
    writerBuilder.settings_["emitUTF8"] = true;

    root["function"] = "updateUserAuthority";
    root["token"] = token;
    for (int i = 0; i < userName.size(); i++)
    {
        user["userName"] = userName[i];
        user["authority"] = authority[i];
        root["user"].append(user);
    }

    // 这里使用智能指针
    std::unique_ptr<Json::StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
    jsonWriter->write(root, &os); // json-->stringstream
    std::string data = os.str(); // 转为string

    return data;
}

std::string insertUser(std::string token, std::string loginName, std::string groupName, std::string userName,
    std::string password, std::string authority)
{
    Json::Value root;
    Json::Value user;

    Json::StreamWriterBuilder writerBuilder; // 新式API
    std::ostringstream os;
    writerBuilder.settings_["emitUTF8"] = true;

    root["function"] = "insertUser";
    root["token"] = token;
    user["loginName"] = loginName;
    user["groupName"] = groupName;
    user["userName"] = userName;
    user["password"] = password;
    user["authority"] = authority;
    root["user"].append(user);

    // 这里使用智能指针
    std::unique_ptr<Json::StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
    jsonWriter->write(root, &os); // json-->stringstream
    std::string data = os.str(); // 转为string

    return data;
}

std::string getUser(std::string token)
{
    Json::Value root;
    Json::Value user;

    Json::StreamWriterBuilder writerBuilder; // 新式API
    std::ostringstream os;
    writerBuilder.settings_["emitUTF8"] = true;

    root["function"] = "getUser";
    root["token"] = token;

    // 这里使用智能指针
    std::unique_ptr<Json::StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
    jsonWriter->write(root, &os); // json-->stringstream
    std::string data = os.str(); // 转为string

    return data;
}


std::string updateGroup(std::string token, std::vector<std::string> newGroupName, std::vector<std::string> oldGroupName)
{
    Json::Value root;
    Json::Value group;

    Json::StreamWriterBuilder writerBuilder; // 新式API
    std::ostringstream os;
    writerBuilder.settings_["emitUTF8"] = true;

    root["function"] = "updateGroup";
    root["token"] = token;
    for (int i = 0; i < newGroupName.size(); i++)
    {
        group["newGroupName"] = newGroupName[i];
        group["oldGroupName"] = oldGroupName[i];
        root["group"].append(group);
    }

    // 这里使用智能指针
    std::unique_ptr<Json::StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
    jsonWriter->write(root, &os); // json-->stringstream
    std::string data = os.str(); // 转为string

    return data;
}

std::string insertGroup(std::string token, std::string groupName)
{
    Json::Value root;
    Json::Value group;

    Json::StreamWriterBuilder writerBuilder; // 新式API
    std::ostringstream os;
    writerBuilder.settings_["emitUTF8"] = true;

    //root.append(userArray);
    root["function"] = "insertGroup";
    root["token"] = token;
    group["groupName"] = groupName;
    root["group"].append(group);

    // 这里使用智能指针
    std::unique_ptr<Json::StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
    jsonWriter->write(root, &os); // json-->stringstream
    std::string data = os.str(); // 转为string

    return data;
}

std::string getGroup(std::string token)
{
    Json::Value root;
    Json::Value projects;

    Json::StreamWriterBuilder writerBuilder; // 新式API
    std::ostringstream os;
    writerBuilder.settings_["emitUTF8"] = true;

    //root.append(userArray);
    root["function"] = "getGroup";
    root["token"] = token;

    // 这里使用智能指针
    std::unique_ptr<Json::StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
    jsonWriter->write(root, &os); // json-->stringstream
    std::string data = os.str(); // 转为string

    return data;
}


//测试用例函数

std::vector<std::string> split(const std::string str, const std::string part)
{
    std::vector<std::string> resVec;

    if ("" == str)//若为空，则返回原字符串
    {
        return resVec;
    }
    //方便截取最后一段数据
    std::string strs = str + part;

    size_t pos = strs.find(part);//find函数的返回值,若找到分隔符返回分隔符第一次出现的位置,否则返回npos
                                 //此处用size_t类型是为了返回位置
    size_t size = strs.size();

    while (pos != std::string::npos)
    {
        std::string x = strs.substr(0, pos);//substr函数，获得子字符串
        resVec.push_back(x);
        strs = strs.substr(pos + 1, size);
        pos = strs.find(part);
    }
    return resVec;
}

std::string encryptMd5(std::string str)
{
    std::string digest;
    CryptoPP::Weak1::MD5 md5;
    CryptoPP::HashFilter hashfilter(md5);
    hashfilter.Attach(new CryptoPP::HexEncoder(new CryptoPP::StringSink(digest), false));
    hashfilter.Put(reinterpret_cast<const unsigned char*>(str.c_str()), str.length());
    hashfilter.MessageEnd();
    return digest;
}

#endif