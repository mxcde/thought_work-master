#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include "uav.h"
int main()
{
	std::string str;
	

	UAV  uav;
	std::cout << "例如：1 2 3 4 ；代表信号1 2 3 4 " << std::endl;
	std::cout << "请输入指定的Signal: ";
	std::getline(std::cin, str);
	uav.setUAVsignal(str);


	/*std::string filename("uav.txt");
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
		uavname = line.substr(0, div_pose); //  uavname  的判断
		upath = line.substr(div_pose + 1, line.size());
		
		tmp.push_back(10); // 判断此项是否为故障 10 真  非 10 故障
		if ((uavname[0] >= '0'&&uavname[0] <= '9') || (uavname[uavname.size() - 1]<'0'||uavname[uavname.size() - 1]>'9'))
		{
			tmp[1] = 11; /// filename  错误
		}
		///  取数应以空格隔开
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
						tmp[1] = 12;///路径出现 非数字 规则1的错误
						break;
					}
				}
				tb.push_back(tmpup);				
				if (i == upath.size())break;
			}
			if (tmp[1] != 12)
			{
             tmp.push_back(std::stoi(tb));
			}		
			tb.clear();		
		}
		uavpath.push_back(tmp);
	}

	
	for (int i = 0; i < uavpath.size()-1;i++)
	{
		
		if (uavpath[i][1] != 10)
	    {
			for(int j=i;j<uavpath.size()-1;j++)
			{ 
		     uavpath[++i][1] = 14;///规则三的错误
			}
			break;
        }

		if((uavpath[i].size() < uavpath[i+1].size() )|| (uavpath[i].size() == 5 && uavpath[i + 1].size()==5 ))
		{ 
			if (uavpath[i][2] != uavpath[i + 1][2] || uavpath[i][3] != uavpath[i + 1][3] || uavpath[i][4] != uavpath[i + 1][4])
			{
				uavpath[i + 1][1] = 13;/////////  规则二  路径关系错误
			}
				
		}
		if ((uavpath[i].size() > uavpath[i + 1].size() )||(uavpath[i].size() ==8 &&  uavpath[i + 1].size()==8 ))
		{
			if (uavpath[i + 1][2] != uavpath[i][2] + uavpath[i][5] || uavpath[i + 1][3] != uavpath[i][3] + uavpath[i][6] || uavpath[i + 1][4] != uavpath[i][4] + uavpath[i][7])
			{
				uavpath[i + 1][1] = 13;/////////  规则二  路径关系错误
			}
		}
		

		
	}
	 
         */

	
	/*for (int i = 0; i < UAVsignal.size(); i++)
	{
		if (UAVsignal[i] > uavpath.size()-1)
		{
			std::cout << "UAVsignal[i]" << std::endl;
			std::cout << "故障" << std::endl;
			continue;
		}
		if (uavpath[UAVsignal[i]][1] != 10)
		{
			std::cout << uavpath[UAVsignal[i]][1] << std::endl;
			std::cout << "故障" << std::endl;
		}
	}

	*/
	
	std::cout << __FILE__ << std::endl;

	getchar();
  return 0;
}

