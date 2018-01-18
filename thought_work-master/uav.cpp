#include "uav.h"
#include<fstream>
#include<istream>

UAV::UAV()
{

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
       if(line =="[uav_signal]")
       {
           while(std::getline(ifile,line))
           {
               int div_pose = line.find("=");
              tmp =line.substr(div_pose+1,line.size()-1) ;
              tmp0 =atoi(tmp.c_str());
              signal.push_back(tmp0);
           }
           continue;
       }
    }

}

void UAV::readuavfile()
{
    std::vector<int> tmp;
    std::ifstream ifile(filename);
    std::string  line;
    std::string upath;
    while(std::getline(ifile,line))
    {
            int div_pose = line.find(" ");
            uavname =line.substr(0,div_pose); //  uavname  的判断
            upath = line.substr(div_pose+1,line.size());
            tmp.clear();
            tmp.push_back(10); // 判断此项是否为故障 10 真  非 10 (11)故障
			if ((uavname[0] >= '0'&&uavname[0] <= '9') || (uavname[uavname.size() - 1]<'0' || uavname[uavname.size() - 1]>'9'))
			{
				tmp[0] = 11;
			}
            for(int i= 0;i<upath.size();i++)
            {
                if(upath[i] == ' ')
                {
                    continue;
                }
                if(upath[i] == '-')
                {
                   int a= upath[++i]-'0';
                   tmp.push_back(0-a);
                   continue;
                }
                tmp.push_back(upath[i]-'0');
            }
            uavpath.push_back(tmp);
    }
	/*
	std::string filename("uav.txt");
	std::string  uavname;
	std::vector<int> tmp;
	std::ifstream ifile(filename);
	std::string  line;
	std::string upath;
	std::vector<std::vector<int>>  uavpath;
	//std::vector<int>  tmp;
	while (std::getline(ifile, line))
	{
		//std::cout << line.c_str() << std::endl;
		line = line.substr(2, line.size() - 1);
		std::cout << line.c_str() << std::endl;
		int div_pose = line.find(" ");
		uavname = line.substr(0, div_pose); //  uavname  的判断
		upath = line.substr(div_pose + 1, line.size());
		tmp.clear();
		tmp.push_back(10); // 判断此项是否为故障 10 真  非 10 故障
		if ((uavname[0] >= '0'&&uavname[0] <= '9') || (uavname[uavname.size() - 1]<'0'||uavname[uavname.size() - 1]>'9'))
		{
			tmp[0] = 11;
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
						tmp[0] = 12;///路径出现 非数字 规则1的错误
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
			 uavpath[++i][0] = 14;///规则三的错误
			}
			break;
		}

		if((uavpath[i].size() < uavpath[i+1].size() )|| (uavpath[i].size() == 4 && uavpath[i + 1].size()==4 ))
		{
			if (uavpath[i][1] != uavpath[i + 1][1] || uavpath[i][2] != uavpath[i + 1][2] || uavpath[i][3] != uavpath[i + 1][3])
			{
				uavpath[i + 1][0] = 13;/////////  规则二  路径关系错误
			}

		}
		if ((uavpath[i].size() > uavpath[i + 1].size() )||(uavpath[i].size() ==7 &&  uavpath[i + 1].size()==7 ))
		{
			if (uavpath[i + 1][1] != uavpath[i][1] + uavpath[i][4] || uavpath[i + 1][2] != uavpath[i][2] + uavpath[i][5] || uavpath[i + 1][3] != uavpath[i][3] + uavpath[i][6])
			{
				uavpath[i + 1][0] = 13;/////////  规则二  路径关系错误
			}
		}



	}*/

}

