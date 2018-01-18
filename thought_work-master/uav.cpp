#include "uav.h"
#include<fstream>
#include<istream>

UAV::UAV()
{
	redconfig();
	readuavfile();
}


void UAV::setUAVsignal(std::string str)
{
	std::string  substr;

	for (int i = 0; i < str.size();)
	{
		while (str[i] != ' ')
		{
			char ch = str[i++];
			if (ch<'0' || ch>'9')
			{
				std::cout << "输入Signal不合法." << std::endl;
				return ;
			}
			substr.push_back(ch);
			if (i == str.size())break;
		}
		i++;
		std::cout << substr << std::endl;
		UAVsignal.push_back(std::stoi(substr));
		substr.clear();
	}

	rulejudge();
}

void UAV::redconfig()
{
    std::ifstream ifile("config.ini");
    std::string  line;
    std::string tmp;
    int tmp0;
    while(std::getline(ifile,line))
    {
       if(line== "[uav_fie_path]")
        {
            std::getline(ifile,line);
            int div_pose = line.find("=");
            filename =line.substr(div_pose+1,line.size()-1);
        }
    }
}

void UAV::readuavfile()
{	
	std::vector<int> tmp;
	std::ifstream ifile("uav.txt");
	std::string  line;
	std::string upath;
	std::vector<std::vector<int>>  uavpath;
	std::string  numberSub;
	while (std::getline(ifile, line))
	{
		int div_pose = line.find(" ");
		tmp.clear();
		numberSub = line.substr(0, div_pose);
		tmp.push_back(std::stoi(numberSub));

		line = line.substr(2, line.size() - 1);
		std::cout << line.c_str() << std::endl;
		div_pose = line.find(" ");
		uavname = line.substr(0, div_pose); //  uavname  的判断
		upath = line.substr(div_pose + 1, line.size());

		tmp.push_back(10); // 判断此项是否为故障 10 真  非 10 故障
		if ((uavname[0] >= '0'&&uavname[0] <= '9') || (uavname[uavname.size() - 1]<'0' || uavname[uavname.size() - 1]>'9'))
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
			while (upath[i] != ' ')
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
	for (int i = 0; i < uavpath.size() - 1; i++)
	{

		if (uavpath[i][1] != 10)
		{
			for (int j = i; j < uavpath.size() - 1; j++)
			{
				uavpath[++i][1] = 14;///规则三的错误
			}
			break;
		}

		if ((uavpath[i].size() < uavpath[i + 1].size()) || (uavpath[i].size() == 5 && uavpath[i + 1].size() == 5))
		{
			if (uavpath[i][2] != uavpath[i + 1][2] || uavpath[i][3] != uavpath[i + 1][3] || uavpath[i][4] != uavpath[i + 1][4])
			{
				uavpath[i + 1][1] = 13;/////////  规则二  路径关系错误
			}

		}
		if ((uavpath[i].size() > uavpath[i + 1].size()) || (uavpath[i].size() == 8 && uavpath[i + 1].size() == 8))
		{
			if (uavpath[i + 1][2] != uavpath[i][2] + uavpath[i][5] || uavpath[i + 1][3] != uavpath[i][3] + uavpath[i][6] || uavpath[i + 1][4] != uavpath[i][4] + uavpath[i][7])
			{
				uavpath[i + 1][1] = 13;/////////  规则二  路径关系错误
			}
		}

	}

}

void UAV::rulejudge()
{
	for (int i = 0; i < UAVsignal.size(); i++)
	{
		if (UAVsignal[i] > uavpath.size() - 1)
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



}

