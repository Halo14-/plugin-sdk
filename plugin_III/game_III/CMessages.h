/*
    Plugin-SDK (Grand Theft Auto) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "plbase\PluginBase_III.h"

struct Message {
    wchar_t        *m_pText;
    unsigned short  m_nFlag;
private:
    char _pad6[2];
public:
    unsigned int    m_nTime;
    unsigned int    m_nStartTime;
    int             m_nNumber[6];
    wchar_t        *m_pString;
};

VALIDATE_SIZE(Message, 0x2C);

struct BigMessage {
    Message m_Current;
    Message m_Stack[3];
};

VALIDATE_SIZE(BigMessage, 0xB0);

struct PreviousBrief {
    wchar_t *m_pText;
    int      m_nNumber[6];
    wchar_t *m_pString;
};

VALIDATE_SIZE(PreviousBrief, 0x20);

class CMessages {
public:
    static PreviousBrief *PreviousBriefs; // static PreviousBrief PreviousBriefs[5]
    static Message *BriefMessages; // static Message BriefMessages[8];
    static BigMessage *BIGMessages; // static BigMessage BIGMessages[6];

    static void Init();
    static int GetWideStringLength(wchar_t* str);
    static int WideStringCopy(wchar_t* dst, wchar_t* src, unsigned short size);
    static bool WideStringCompare(wchar_t* str1, wchar_t* str2, unsigned short size);
    static void Process();
    static void Display();
    static void AddMessage(wchar_t* text, unsigned int time, unsigned short flag);
    static void AddMessageJumpQ(wchar_t* text, unsigned int time, unsigned short flag);
    static void AddMessageSoon(wchar_t* text, unsigned int time, unsigned short flag);
    static void ClearMessages();
    static void ClearSmallMessagesOnly();
    static void AddBigMessage(wchar_t* text, unsigned int time, unsigned short flag);
    static void AddBigMessageQ(wchar_t* text, unsigned int time, unsigned short flag);
    static void AddToPreviousBriefArray(wchar_t* text, int n1, int n2, int n3, int n4, int n5, int n6, wchar_t* str);
    static void InsertNumberInString(wchar_t* src, int n1, int n2, int n3, int n4, int n5, int n6, wchar_t* dst);
    static void InsertStringInString(wchar_t* text, wchar_t* str);
    static void InsertPlayerControlKeysInString(wchar_t* text);
    static void AddMessageWithNumber(wchar_t* text, unsigned int time, unsigned short flag, int n1, int n2, int n3, int n4, int n5, int n6);
    static void AddMessageJumpQWithNumber(wchar_t* text, unsigned int time, unsigned short flag, int n1, int n2, int n3, int n4, int n5, int n6);
    static void AddMessageSoonWithNumber(wchar_t* text, unsigned int time, unsigned short flag, int n1, int n2, int n3, int n4, int n5, int n6);
    static void AddBigMessageWithNumber(wchar_t* text, unsigned int time, unsigned short flag, int n1, int n2, int n3, int n4, int n5, int n6);
    static void AddBigMessageWithNumberQ(wchar_t* text, unsigned int time, unsigned short flag, int n1, int n2, int n3, int n4, int n5, int n6);
    static void AddMessageWithString(wchar_t* text, unsigned int time, unsigned short flag, wchar_t* str);
    static void AddMessageJumpQWithString(wchar_t* text, unsigned int time, unsigned short flag, wchar_t* str);
    static void ClearThisPrint(wchar_t* text);
    static void ClearThisBigPrint(wchar_t* text);
    static void ClearAllMessagesDisplayedByGame();
};