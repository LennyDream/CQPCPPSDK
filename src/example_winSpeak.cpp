#include <CQEVE_GroupMsg.h>
#include <winSpeak.h>
#include <CQcode.h>

#include <string>

using namespace std;
using namespace CQ;

//这个字段有注释


EVE_GroupMsg_EX(Speak) {

	static string msgs("Speak:");

	if (eve.message.compare(0, msgs.size(), msgs))return;

	auto txt = eve.message.substr(msgs.size());

	eve.sendMsg() << code::record("out.wav", txt) << send;
	//record 的第一个参数指示将语音生成到哪个文件(相对于酷Q的语音目录)
	//record 的第二个参数指示将指定文字生成语音
}