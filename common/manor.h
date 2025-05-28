#pragma once

#include "typedefs.h"

enum
{
	MSG_ROOMAVAILID = 0x41526d49, /// Room available ID
	MSG_AUTHLIST = 0x41754c73,    /// Auth list
	MSG_BASEURL = 0x4255726c,     /// Base URL
	MSG_BADGE = 0x42616467,       /// Badge
	MSG_BANLIST = 0x426e4c73,     /// Ban list
	MSG_CMDLIST = 0x436d4c73,     /// Command list
	MSG_ROOMNEW = 0x4372626d,
	MSG_TALKCRYPT = 0x4372546b,
	MSG_DATA = 0x44617461,                /// Data
	MSG_LOOSEPROPDEL = 0x446c5072,        /// Loose prop delete
	MSG_FILERECEIVED = 0x4641636b,        /// File received
	MSG_USERFACE = 0x46496d67,            /// User face
	MSG_USERSETFACE = 0x464e756d,         /// User set face
	MSG_USERCOLOR = 0x46524742,           /// User color
	MSG_GIVEPROP = 0x47507270,            /// Give prop
	MSG_LISTOFALLGROUPS = 0x47724c73,     /// List of all groups
	MSG_GROUP = 0x47727570,               /// Group
	MSG_IDENT = 0x49646e32,               /// Identification
	MSG_KILLUSER = 0x4b696c6c,            /// Kill user
	MSG_LOGMSG = 0x4c4d7367,              /// Log message
	MSG_LOOSEPROP = 0x4c507270,           /// Loose prop
	MSG_LISTOFALLLOOSEPROPS = 0x4c704c73, /// List of all loose props
	MSG_PROPMOVE = 0x4d4c5072,            /// Prop move
	MSG_USERMOVE3D = 0x4d763344,          /// User move 3D
	MSG_USERNAME = 0x4e616d65,            /// User name
	MSG_PROPDATA = 0x50447461,            /// Prop data
	MSG_PROPURL = 0x5055726c,             /// Prop URL
	MSG_PERMISSION = 0x5065726d,          /// Permission
	MSG_PING = 0x50696e67,                /// Ping
	MSG_PROPLIST = 0x506c7374,            /// Prop list
	MSG_POST = 0x506f7374,                /// Post
	MSG_PERMISSIONLIST = 0x50724c73,      /// Permission list
	MSG_ROOMSETDESC = 0x5245496e,         /// Room set description
	MSG_PROPDEL = 0x52507270,             /// Prop delete
	MSG_ROOMLISTEND = 0x526c5374,         /// Room list end
	MSG_ROOMUPDATE = 0x526c5564,          /// Room update
	MSG_USERENTER = 0x526d456e,           /// User enter
	MSG_ROOMENTER = 0x526d496e,           /// Room enter
	MSG_ROOMLOCK = 0x526d4c6b,            /// Room lock
	MSG_ROOMNAME = 0x526d4e6d,            /// Room name
	MSG_ROOMOCC = 0x526d4f63,             /// Room occupancy
	MSG_ROOMREQUEST = 0x526d5271,         /// Room request
	MSG_LISTOFALLROOMS = 0x526d6c73,      /// List of all rooms
	MSG_ROOMDESC = 0x526f6f6d,            /// Room description
	MSG_SERVERNAME = 0x534e6d65,          /// Server name
	MSG_SNDLIST = 0x53644c73,             /// Sound list
	MSG_SPOTSTATE = 0x53705374,           /// Spot state
	MSG_TALK = 0x54616c6b,                /// Talk
	MSG_USERLISTEND = 0x556c5374,         /// User list end
	MSG_USERLISTUPDATE = 0x556c5564,      /// User list update
	MSG_LISTOFALLUSERS = 0x556c6c73,      /// List of all users
	MSG_ROOMAUTHOR = 0x5570526d,          /// Room author
	MSG_USERLOG = 0x55734374,             /// User log
	MSG_USERMOVE = 0x55734d76,            /// User move
	MSG_VOICE = 0x566f6963,               /// Voice
	MSG_AUTHREQUEST = 0x61757468,         /// Auth request
	MSG_FILESEGMENT = 0x66536567,         /// File segment
	MSG_XTALK = 0x78546c6b,
};

enum
{
	RF_DropZone = 1,         /// Drop zone
	RF_NoGuests = 2,         /// No guests
	RF_Timeout = 4,          /// Timeout
	RF_Private = 8,          /// Private room
	RF_Hidden = 16,          /// Hidden room
	RF_WizardsOnly = 32,     /// Wizards only
	RF_NoLooseProps = 64,    /// No loose props
	RF_NoPainting = 128,     /// No painting
	RF_NoWhispering = 256,   /// No whispering
	RF_CyborgFreeZone = 512, /// Cyborg free zone
	RF_NoSpoofing = 1024,    /// No spoofing
};

enum
{
	U_Honorary = 32,       /// Honorary user
	U_RejectPrivate = 128, /// Reject private messages
};
