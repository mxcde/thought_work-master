#include <iostream>
#include<fstream>
#include<string>
#include<vector>
int main()
{
	std::string filename("uav.txt");
	std::string  uavname;
	std::vector<int> tmp;
	std::ifstream ifile(filename);
	std::string  line;
	std::string upath;
	std::vector<std::vector<int>>  uavpath;
	std::string  numberSub;
	//std::vector<int>  tmp;
	while (std::getline(ifile, line))
	{
		int div_pose = line.find(" ");
		tmp.clear();
		//std::cout << line.c_str() << std::endl;
		numberSub = line.substr(0, div_pose);
		tmp.push_back(std::stoi(numberSub));

		line = line.substr(2, line.size() - 1);
		std::cout << line.c_str() << std::endl;
	    div_pose = line.find(" ");
		uavname = line.substr(0, div_pose); //  uavname  ���ж�
		upath = line.substr(div_pose + 1, line.size());
		
		/*tmp.push_back(10); // �жϴ����Ƿ�Ϊ���� 10 ��  �� 10 ����
		if ((uavname[0] >= '0'&&uavname[0] <= '9') || (uavname[uavname.size() - 1]<'0'||uavname[uavname.size() - 1]>'9'))
		{
			tmp[0] = 11;
		}
		///  ȡ��Ӧ�Կո����
		std::string   tb;
		for (int i = 0; i < upath.size();)
		{
			if (upath[i] == ' ')
			{
				i++;
			}
			while (upath[i]!=' ')
			{
				char tmpup = upath[i++];
				if (tmpup != '-')
				{
					if (tmpup<'0' || tmpup>'9')
					{
						tmp[0] = 12;///·������ ������ ����1�Ĵ���
						break;
					}
				}
				tb.push_back(tmpup);				
				if (i == upath.size())break;
			}
			if (tmp[0] != 12)
			{
             tmp.push_back(std::stoi(tb));
			}		
			tb.clear();		
		}
		uavpath.push_back(tmp);
	}

	
	for (int i = 0; i < uavpath.size()-1;i++)
	{
		
		if (uavpath[i][0] != 10)
	    {
			for(int j=i;j<uavpath.size()-1;j++)
			{ 
		     uavpath[++i][0] = 14;///�������Ĵ���
			}
			break;
        }

		if((uavpath[i].size() < uavpath[i+1].size() )|| (uavpath[i].size() == 4 && uavpath[i + 1].size()==4 ))
		{ 
			if (uavpath[i][1] != uavpath[i + 1][1] || uavpath[i][2] != uavpath[i + 1][2] || uavpath[i][3] != uavpath[i + 1][3])
			{
				uavpath[i + 1][0] = 13;/////////  �����  ·����ϵ����
			}
				
		}
		if ((uavpath[i].size() > uavpath[i + 1].size() )||(uavpath[i].size() ==7 &&  uavpath[i + 1].size()==7 ))
		{
			if (uavpath[i + 1][1] != uavpath[i][1] + uavpath[i][4] || uavpath[i + 1][2] != uavpath[i][2] + uavpath[i][5] || uavpath[i + 1][3] != uavpath[i][3] + uavpath[i][6])
			{
				uavpath[i + 1][0] = 13;/////////  �����  ·����ϵ����
			}
		}
		*/

		
	}
	 
         
	/*std::vector<int> UAVsignal;
	
	std::string  str;
	std::string  substr;
	std::cout << "���磺1 2 3 4 �������ź�1 2 3 4 " << std::endl;
	std::cout << "������ָ����Signal: ";
	std::getline(std::cin, str);
	
	for (int i = 0; i < str.size();)
	{
		while (str[i] != ' ')
		{
			char ch = str[i++];
			if (ch<'0' || ch>'9')
			{
				std::cout << "����Signal ���Ϸ���" << std::endl;
				return 0;
			}
			substr.push_back(ch);
			if (i == str.size())break;
		}
		i++;

		std::cout << substr << std::endl;
		UAVsignal.push_back(std::stoi(substr));
		substr.clear();
	}
	
	for (int i = 0; i < UAVsignal.size(); i++)
	{
		if (UAVsignal[i] > uavpath.size())
		{
			std::cout << "UAVsignal[i]" << std::endl;
			std::cout << "����" << std::endl;
		}
		if (uavpath[UAVsignal[i]][0] != 10)
		{
			std::cout << uavpath[UAVsignal[i]][0] << std::endl;
			std::cout << "����" << std::endl;
		}
	}


	*/
	std::cout << __FILE__ << std::endl;

	getchar();
  return 0;
}

