#ifndef COPERATION_H
#define COPERATION_H

#include <iostream>
#include <vector>
#include <cryptopp/cryptlib.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>
#include <cryptopp/files.h>
#include <cryptopp/hex.h>

using namespace CryptoPP;

std::vector<std::string> split(const std::string str, const std::string part)
{
    std::vector<std::string> resVec;

    if ("" == str)//��Ϊ�գ��򷵻�ԭ�ַ���
    {
        return resVec;
    }
    //�����ȡ���һ������
    std::string strs = str + part;

    size_t pos = strs.find(part);//find�����ķ���ֵ�����ҵ��ָ������طָ�����һ�γ��ֵ�λ�ã�
                                 //���򷵻�npos
                                 //�˴���size_t������Ϊ�˷���λ��
    size_t size = strs.size();

    while (pos != std::string::npos)
    {
        std::string x = strs.substr(0, pos);//substr������������ַ���
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