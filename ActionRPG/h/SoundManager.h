#ifndef SoundManager_h_
#define SoundManager_h_

#include<map>
#include<string>

enum SoundState
	{
		State_Error = -1,		//失敗
		State_None,				//行動しない
		State_Success,			//成功
		State_Num				//最大値
	};

class SoundMng
{
public:
	static SoundMng* Instance()
	{
		static SoundMng instance;
		return &instance;
	}

private:


public:
	bool Load(const char* filename, std::string keyword);
	void Play(std::string keyword, int playtype = 0, int toppositionflag = 0);
	void Stop(std::string keyword);
	void Release(std::string keyword);
	void AllRelease();

private:
	std::map<std::string, int>m_SoundList;
	SoundMng() {}
	~SoundMng() { AllRelease(); }

};


#endif