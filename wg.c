
/*
 * 设备上传命令回调
 *
 * dwType : 命令功能码
 * pParam : 命令参数
 */


typedef Int32 (__stdcall *CallbackFunction)(DWORD dwType, void* pData, void* pParam);

//
// 超频功能回调
#define OVERLOCK_TYPE_START (0)
#define OVERLOCK_TYPE_STOP (1)
/*
 * OverLockFunc
 * pParam : 0 - 开启超频 ,  1 - 停止超频
 *
 * 注意: 开启或者停止超频完成的时候，需要调用设置超频状态 SetOverLockState 函数通知设备超频结果.
 */
Int32 RegisterOverLock(CallbackFunction OverLockFunc, void* pParam);

//
// 设备获取超频状态回调
/*
 * func
 *        pParam 值（  : 1 - 普通模式 ,  2 - 超频模式
 */
Int32 RegisterGetOverLockState(CallbackFunction func, void* pParam);

//
// 设备获取cpu频率回调
/*
 * func
*       pParam 值 (float32) : 例如 4.8 M 则 *pParam = 4.8
*/
Int32 RegisterGetCPU(CallbackFunction func, void* pParam);

//
// 设备获取PC工作模式回调
/*
 * func
*       pParam 值  : 1 - 普通模式 , 2 - 游戏模式 , 3 - 待机模式, 4 - 其他模式
*/
Int32 RegisterGetMode(CallbackFunction func, void* pParam);


/*
 * 设置超频状态
 *  
 *  state 为 0 表示普通模式
 *  state 为 1 表示超频模式 
*/
void SetOverLockState(Int32 state);

/*
 * 设置频率
 *
 *  fq: 当前频率值， 单位为 MHz
 * 
 * 例如 4.8Mhz , fq = 4.8
*/
void SetFq(Float32 fq);

/*
 * 设置PC工作模式
 *  
 *  mode: 
 *  1 普通模式
 *  2 游戏模式
 *  3 待机模式
 *  4 其他模式
*/
void SetMode(Int32 mode);

/*
 * 初始化设备接口
 *
 * 返回 0 代表成功， 其他值为失败
 */
Int32 Init();

/*
 * 释放设备接口
 *
 * 返回 0 代表成功， 其他值为失败
 */
Int32 Release();
