#ifndef CATALOGMANAGER_H
#define CATALOGMANAGER_H

#define ATTR_SCHEME_LENGTH 8
#define ATTR_NAME_LENGTH 21
#define PRIMARY_KEY_LENGTH 1
#define UNIQUE_LENGTH 1
#define INDEX_LENGTH 1
#define TABLE_NAME_LENGTH 21
#define INDEX_NAME_LENGTH 21

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class CatalogManager {
private:
	//���ĳһ������ֵ�Ƿ���catalog�еļ�¼�������������Ǻϡ��ú�����judgeAttribute�������á�
	bool checkType(string value, string type);

	
public:
    string getFilePath(string tableName)
    {
        string path = "db\\";
        path = path + tableName;
        path = path + "_attr.db";
        return path;
    }
    
	//�������������ñ��Ƿ����
	bool checkFile(string File) 
	{
		ofstream catalog;
		
		catalog.open(File.c_str(), ios::in);
		if (catalog) {
			return true;
		}
		else {
			return false;
		}
	}
	//����table��������[tablename]_data.txt, [tablename]_attr.txt�����ļ�������������Ե���Ϣ����[tablename]_attr.txt�ļ��У������ɹ�����true�����򷵻�false
	bool createTable(string tableName, vector<string> attributeScheme, vector<string> attributeName, string primaryKey, vector<int>unique);
	//ɾ��table��ɾ���ɹ�����true�����򷵻�false��
	bool dropTable(string tableName);
	//����table���������Ե����ͣ�������һ��vector�����У�������ÿ��ֵ��˳��ֱ���ÿ�����Ե����ͣ�int��float����)
	vector<string> getAttributeScheme(string tableName);
	//����table���������Ե����֣�������һ��vector�����У�������ÿ��ֵ��˳��ֱ���ÿ�����Ե����֣�bno��cno����)
	vector<string> getAttributeName(string tableName);
	//����table���ж��ٸ�����
	int getAttributeNum(string tableName);
	//����������һ��record�е���������ֵ���������record�����������ֵ�Ƿ��������Ӧ���������͡������򷵻�true��ע��float���͵�ֵΪ��1�� .1 �� 1. ʱ������Ϊ����ȷ��
	bool judgeAttribute(string tableName, vector <string> attributeValue);
	//�����������ѱ�������unique�Լ�primary key �����Ե�λ�÷���һ������vector���������vector���磺table��5��attribute�У���0��3��������unique���ͷ�������[0,3]��
	vector<int> getUnique(string tableName);
	//��������������������λ��
	int getPrimaryKey(string tableName);
	//����һ�������������������ظ��������ڸñ����ǵڼ������������������ڱ����򷵻�-1��ע�����еĵ�һ������������ֵΪ0�����Դ����ơ�
	int getAttributePosition(string tableName, string attributeName);
	//��������
	bool createIndex(string tableName, string attributeName, string indexName);
	//ɾ������
	bool dropIndex(string indexName);
	//������������������Ѱ�ҷ��ظ����Զ�Ӧ�����������֡������������������򷵻ؿ��ַ���
	string getIndexName(string tableName, string attributeName);
	//�жϸ������Ƿ���ڣ�������������Ѿ����ڣ��򷵻�true�����򷵻�false
	bool checkIndex(string indexName);
    //������еĵ�������
    vector <string> getAllIndex();
    //types.
    vector <string> getAllIndexType();
};
#endif
