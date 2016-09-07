// #pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <mutex>
#include <atomic>

#ifdef __GNUC__
#include "dirent.h"
#else
#include "dirent_win.h"
#endif

using namespace std;


class Logger
{
public:
	enum eLogLevel
	{
		log_L0,
		log_L1,
		log_L2,
		log_L3,
		log_error,
	};

	enum eLogDirection
	{
		to_file,
		to_console,
		to_console_and_file
	};

	static Logger* get()
	{
		static Logger self;
		return &self;
	}


	void init(std::string logPath, eLogLevel level, eLogDirection direction)
	{
		if (m_log_file.is_open())
			m_log_file.close();

		m_path = logPath;
		m_currentLevel = level;
		m_direction = direction;

		//
	}

	void write(eLogLevel level, std::string module, std::string msg)
	{

	}


private:
	using tFile = std::ofstream;

	tFile m_log_file;
	std::string m_path;
	eLogLevel m_currentLevel = log_L0;
	eLogDirection m_direction = to_console;
	std::atomic<bool> m_isInited;


	Logger()
	{
		m_isInited = false;
		cout << __FUNCTION__ << endl;


		cout << "dir" << endl;
		DIR *dp;
		  struct dirent *ep;     
		  dp = opendir ("./");

		  if (dp != NULL)
		  {
		    while ((ep = readdir(dp)) != NULL)
		      cout << (ep->d_name) << endl;

		    (void) closedir (dp);
		  }
		  else
		    cout << ("Couldn't open the directory") << endl;

	}

	~Logger()
	{
		cout << __FUNCTION__ << endl;
		release();
	}

	void release()
	{

	}
};


int main()
{
	{
		Logger* logger = Logger::get();
	}

	return 0;
}