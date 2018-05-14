
/*
 * 超频按键回调
 *
 * startOverLockFun: 开始超频的回调函数
 *     返回 0 代表成功， 其他值为失败
 *
 * stopOverLockFun: 停止超频的回调函数
 *     返回 0 代表成功， 其他值为失败
 */
typedef Int32 (*CallbackFunction)(void);

Int32 RegisterOverLock(CallbackFunction startOverLockFun, CallbackFunction stopOverLockFun);


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
