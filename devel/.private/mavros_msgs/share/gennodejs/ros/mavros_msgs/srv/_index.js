
"use strict";

let CommandBool = require('./CommandBool.js')
let CommandHome = require('./CommandHome.js')
let CommandInt = require('./CommandInt.js')
let CommandLong = require('./CommandLong.js')
let CommandTOL = require('./CommandTOL.js')
let CommandTriggerControl = require('./CommandTriggerControl.js')
let CommandTriggerInterval = require('./CommandTriggerInterval.js')
let CommandVtolTransition = require('./CommandVtolTransition.js')
let FileChecksum = require('./FileChecksum.js')
let FileClose = require('./FileClose.js')
let FileList = require('./FileList.js')
let FileMakeDir = require('./FileMakeDir.js')
let FileOpen = require('./FileOpen.js')
let FileRead = require('./FileRead.js')
let FileRemove = require('./FileRemove.js')
let FileRemoveDir = require('./FileRemoveDir.js')
let FileRename = require('./FileRename.js')
let FileTruncate = require('./FileTruncate.js')
let FileWrite = require('./FileWrite.js')
let LogRequestData = require('./LogRequestData.js')
let LogRequestEnd = require('./LogRequestEnd.js')
let LogRequestList = require('./LogRequestList.js')
let MessageInterval = require('./MessageInterval.js')
let MountConfigure = require('./MountConfigure.js')
let ParamGet = require('./ParamGet.js')
let ParamPull = require('./ParamPull.js')
let ParamPush = require('./ParamPush.js')
let ParamSet = require('./ParamSet.js')
let SetMavFrame = require('./SetMavFrame.js')
let SetMode = require('./SetMode.js')
let StreamRate = require('./StreamRate.js')
let VehicleInfoGet = require('./VehicleInfoGet.js')
let WaypointClear = require('./WaypointClear.js')
let WaypointPull = require('./WaypointPull.js')
let WaypointPush = require('./WaypointPush.js')
let WaypointSetCurrent = require('./WaypointSetCurrent.js')

module.exports = {
  CommandBool: CommandBool,
  CommandHome: CommandHome,
  CommandInt: CommandInt,
  CommandLong: CommandLong,
  CommandTOL: CommandTOL,
  CommandTriggerControl: CommandTriggerControl,
  CommandTriggerInterval: CommandTriggerInterval,
  CommandVtolTransition: CommandVtolTransition,
  FileChecksum: FileChecksum,
  FileClose: FileClose,
  FileList: FileList,
  FileMakeDir: FileMakeDir,
  FileOpen: FileOpen,
  FileRead: FileRead,
  FileRemove: FileRemove,
  FileRemoveDir: FileRemoveDir,
  FileRename: FileRename,
  FileTruncate: FileTruncate,
  FileWrite: FileWrite,
  LogRequestData: LogRequestData,
  LogRequestEnd: LogRequestEnd,
  LogRequestList: LogRequestList,
  MessageInterval: MessageInterval,
  MountConfigure: MountConfigure,
  ParamGet: ParamGet,
  ParamPull: ParamPull,
  ParamPush: ParamPush,
  ParamSet: ParamSet,
  SetMavFrame: SetMavFrame,
  SetMode: SetMode,
  StreamRate: StreamRate,
  VehicleInfoGet: VehicleInfoGet,
  WaypointClear: WaypointClear,
  WaypointPull: WaypointPull,
  WaypointPush: WaypointPush,
  WaypointSetCurrent: WaypointSetCurrent,
};
