using namespace QPI;
#define VLIQUID_CONTRACTID _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 9)

#define MILLION 1000000
#define MAX_TOKENS 8
#define LIQUIDS_LENGTH 128
#define LIQUID_CREATION_FEE 100000000
#define QWALLET_TOKEN 23720092042876753ULL
#define QWALLET_ISSUER_ID _mm256_set_epi8(25, 178, 91, 147, 113, 184, 41, 95, 201, 196, 83, 72, 72, 121, 112, 207, 56, 34, 123, 70, 46, 238, 205, 207, 42, 107, 220, 170, 172, 141, 173, 116)
#define VALIS_ISSUER_ID _mm256_set_epi8(223, 190, 63, 172, 212, 56, 31, 53, 61, 6, 147, 71, 218, 67, 130, 162, 84, 131, 24, 172, 37, 131, 179, 198, 179, 115, 142, 132, 191, 63, 106, 1)

struct VLIQUID2
{
};

struct VLIQUID : public ContractBase
{
public:
    struct ConvertToMicroToken_input
    {
        id issuer;
        uint64 assetName;
        sint64 expensiveTokenAmount;
    };
    struct ConvertToMicroToken_output
    {
        uint64 microTokenAmount;
    };

    struct ConvertToExpensiveToken_input
    {
        id issuer;
        uint64 assetName;
        uint64 microTokenAmount;
    };
    struct ConvertToExpensiveToken_output
    {
        sint64 expensiveTokenAmount;
    };

    struct TransferMicroToken_input
    {
        id issuer;
        uint64 assetName;
        id recipient;
        uint64 microTokenAmount;
    };
    struct TransferMicroToken_output
    {
        uint64 transferredMicroTokenAmount;
    };

    struct MicroTokenAllowance_input
    {
        id issuer;
        uint64 assetName;
        id recipient;
        id spender;
    };
    struct MicroTokenAllowance_output
    {
        uint64 balance;
    };

	struct BalanceOfMicroToken_input
	{
		id issuer;
		uint64 assetName;
		id owner;
	};
	struct BalanceOfMicroToken_output
	{
		uint64 balance;
	};

    struct ApproveMicroToken_input
    {
        id issuer;
        id recipient;
        uint64 assetName;
        uint64 microTokenAmount;
    };
    struct ApproveMicroToken_output
    {
        uint64 approvedMicroTokenAmount;
    };

    struct TransferFromMicroToken_input
    {
        id issuer;
        uint64 assetName;
        id spender;
        id recipient;
        uint64 microTokenAmount;
    };
    struct TransferFromMicroToken_output
    {
        uint64 transferredMicroTokenAmount;
    };

    struct TokenInfo {
        id issuer;
        uint64 assetName;
        bool isMicroToken;
    };
    struct Token {
        TokenInfo tokenInfo;
        uint64 balance;
        uint8 weight;
    };
    struct CreateLiquid_input
    {
        array<Token, MAX_TOKENS> tokens;
		uint8 tokenLength;
		uint64 quShares;
		uint8 quWeight;
		uint16 initialLiquid;
		uint8 feeRate;
    };
    struct CreateLiquid_output
    {
		uint64 liquidId;
    };

    struct AddLiquid_input
    {
		uint64 tokenContribution;
		uint64 liquidId;
    };
    struct AddLiquid_output
    {
		uint64 addedContribution;
    };

    struct RemoveLiquid_input
    {
        uint64 tokenContribution;
		uint64 liquidId;
    };
    struct RemoveLiquid_output
    {
		uint64  removedContribution;
    };

    struct SwapToQU_input
    {
        uint64 liquidId;
        TokenInfo inputTokenInfo;
        uint64 inputAmount;
    };
    struct SwapToQU_output
    {
        uint64 quAmount;
    };

    struct SwapFromQU_input
    {
        uint64 liquidId;
        TokenInfo outputTokenInfo;
        uint64 quAmount;
    };
    struct SwapFromQU_output
    {
        uint64 outputAmount;
    };

    struct SwapToQwallet_input
    {
        uint64 liquidId;
        TokenInfo inputTokenInfo;
        uint64 inputAmount;
    };
    struct SwapToQwallet_output
    {
        uint64 qwalletAmount;
        uint64 quAmount;
    };

    struct SwapFromQwallet_input
    {
        uint64 liquidId;
        TokenInfo outputTokenInfo;
        uint64 qwalletAmount;
    };
    struct SwapFromQwallet_output
    {
        uint64 outputAmount;
        uint64 quAmount;
    };

    struct SwapQUToQwallet_input
    {
        uint64 liquidId;
        uint64 quAmount;
    };
    struct SwapQUToQwallet_output
    {
        uint64 qwalletAmount;
    };

    struct SwapQwalletToQU_input
    {
        uint64 liquidId;
        uint64 qwalletAmount;
    };
    struct SwapQwalletToQU_output
    {
        uint64 quAmount;
    };

    struct SingleSwap_input
    {
        uint64 liquidId;
        TokenInfo inputTokenInfo;
        TokenInfo outputTokenInfo;
        uint64 inputAmount;
    };
    struct SingleSwap_output
    {
        uint64 outputAmount;
        uint64 outputQwalletAmount;
        uint64 outputQuAmount;
    };

    struct CrossSwap_input
    {
        uint64 liquidIdA;
        TokenInfo inputTokenInfoA;
        uint64 inputAmountA;
        uint64 liquidIdB;
        TokenInfo outputTokenInfoB;
    };
    struct CrossSwap_output
    {
        uint64 outputAmountB;
        uint64 outputQwalletAmount;
        uint64 outputQuAmount;
    };

    struct InitializeStakingPool_input
    {
        uint64 liquidId;
        TokenInfo bonusTokenInfo;
    };
    struct InitializeStakingPool_output
    {
        bool success;
    };

    struct DepositeBonusToken_input {
        uint64 liquidId;
        uint64 bonusTokenAmount;
    };
    struct DepositeBonusToken_output {
        uint64 depositedBonusTokenAmount;
    };

    struct Stake_input
    {
        uint64 liquidId;
        uint64 lpAmount;
    };
    struct Stake_output
    {
        uint64 stakedLpAmount;
    };

    struct Unstake_input
    {
        uint64 liquidId;
        uint64 lpAmount;
    };
    struct Unstake_output
    {
        uint64 unstakedLpAmount;
    };

    // Exam
    struct ExamPublic_input
    {
        uint64 inputValue;
    };
    struct ExamPublic_output
    {
        uint64 outputValue;
    };

private:
    // declare state variables
    struct _MicroTokenBalance {
        id owner;
        id issuer;
        uint64 assetName;
        uint64 balance;
    };
    
    array<_MicroTokenBalance, 16777216> _microTokenBalances;
    uint64 _microTokenBalancesLength;

    struct _MicroTokenAllowance {
        id recipient;
        id spender;
        id issuer;
        uint64 assetName;
        uint64 balance;
    };

    array<_MicroTokenAllowance, 16777216> _microTokenAllowances;
    uint64 _microTokenAllowancesLength;

	struct _BalanceOfMicroToken_input {
		id issuer;
		uint64 assetName;
		id owner;
	};
	struct _BalanceOfMicroToken_output {
		uint64 balance;
	};

    struct _MintMicroToken_input
    {
        id issuer;
        uint64 assetName;
        uint64 microTokenAmount;
    };
    struct _MintMicroToken_output
    {
        uint64 mintedMicroTokenAmount;
    };

    struct _BurnMicroToken_input
    {
        id issuer;
        uint64 assetName;
        uint64 microTokenAmount;
    };
    struct _BurnMicroToken_output
    {
        uint64 burntMicroTokenAmount;
    };

    struct _LockExpensiveToken_input
    {
        id issuer;
        uint64 assetName;
        sint64 expensiveTokenAmount;
    };
    struct _LockExpensiveToken_output
    {
        sint64 lockedExpensiveTokenAmount;
    };

    struct _UnLockExpensiveToken_input
    {
        id issuer;
        uint64 assetName;
        uint64 expensiveTokenAmount;
    };
    struct _UnLockExpensiveToken_output
    {
        sint64 unLockedExpensiveTokenAmount;
    };

	struct _LiquidInfo {
		struct LiquidProvider {
			id owner;
			uint64 tokenContributions;
		};
		array<Token, MAX_TOKENS> tokens;
		uint8 tokenLength;
		uint64 quBalance;
		uint8 quWeight;
		uint16 totalWeight;
		uint64 totalLiquid;
		uint16 feeRate;
		array<LiquidProvider, 131072> liquidProviders;
		uint64 liquidProvidersCount;
        id owner;
		id creator;
		bool isCreated;
	};

    _LiquidInfo _tempLiquid;

	array<_LiquidInfo, LIQUIDS_LENGTH> _liquids;
	uint64 _liquidsCount;

    struct _Staker {
        id stakerId;
        uint64 stakedAmount;
        uint64 rewardDebt;
    };

    struct _StakingPool {
        uint64 liquidId;
        uint64 totalStaked;
        TokenInfo bonusTokenInfo;
        uint64 totalBonusTokenAmount;
        uint64 accPerShare;
        uint64 lastRewardTick;
        bool isInitialized;
        array <_Staker, 32768> stakers;
        uint64 stakerCount;
    };

    _StakingPool _tempStakingPool;

    array<_StakingPool, LIQUIDS_LENGTH> _stakingPools;
    uint64 _stakingPoolsCount;

    struct _ExamPrivate_input
    {
        id inputValue;
    };
    struct _ExamPrivate_output
    {
        id outputValue1;
        uint64 outputValue2;
    };
    

    // write PRIVATE_FUNCTION_WITH_LOCALS
    struct _BalanceOfMicroToken_locals {
        _MicroTokenBalance _balance;
    };
	PRIVATE_FUNCTION_WITH_LOCALS(_BalanceOfMicroToken)
		output.balance = 0;
		for (uint64 i = 0; i < state._microTokenBalancesLength; i ++)
		{
            locals._balance = state._microTokenBalances.get(i);
			if (locals._balance.issuer == input.issuer &&
				locals._balance.assetName == input.assetName &&
				locals._balance.owner == input.owner)
			{
				output.balance = locals._balance.balance;
				break;
			}
		}
    _

    struct _ExamPrivate_locals {
        uint64 _i;
    };
    PRIVATE_FUNCTION_WITH_LOCALS(_ExamPrivate)
        locals._i = 1;
        locals._i++;
        output.outputValue1 = input.inputValue;
        output.outputValue2 = locals._i;
    _

	// write PRIVATE_PROCEDURE_WITH_LOCALS
    struct _MintMicroToken_locals
    {
        bool _balanceFound;
        _MicroTokenBalance _newBalance;
    };
    PRIVATE_PROCEDURE_WITH_LOCALS(_MintMicroToken)
        locals._balanceFound = false;
        output.mintedMicroTokenAmount = 0;
        // Iterate over balances to find the matching balance for the issuer and asset
        for (uint64 i = 0; i < state._microTokenBalancesLength; ++i)
        {
            locals._newBalance= state._microTokenBalances.get(i);
            if (locals._newBalance.issuer == input.issuer
                && locals._newBalance.assetName == input.assetName
                && locals._newBalance.owner == qpi.invocator())
            {
                // Add the minted amount to the existing balance
                locals._newBalance.balance += input.microTokenAmount;
                state._microTokenBalances.set(i, locals._newBalance);
                locals._balanceFound = true;
                output.mintedMicroTokenAmount = input.microTokenAmount;
                break;
            }
        }

        // If no existing balance was found, create a new balance entry
        if (!locals._balanceFound)
        {
            locals._newBalance.issuer = input.issuer;
            locals._newBalance.assetName = input.assetName;
            locals._newBalance.owner = qpi.invocator();
            locals._newBalance.balance = input.microTokenAmount;
            state._microTokenBalances.set(state._microTokenBalancesLength + 1, locals._newBalance);
            state._microTokenBalancesLength++;
            output.mintedMicroTokenAmount = input.microTokenAmount;
        }
    _

    struct _BurnMicroToken_locals
    {
        bool _balanceFound;
        _MicroTokenBalance _newBalance;
    };
    PRIVATE_PROCEDURE_WITH_LOCALS(_BurnMicroToken)
        locals._balanceFound = false;
        output.burntMicroTokenAmount = 0;

        // Iterate over balances to find the matching balance for the issuer and asset
        for (uint64 i = 0; i < state._microTokenBalancesLength; i ++)
        {
            locals._newBalance = state._microTokenBalances.get(i);
            if (locals._newBalance.issuer == input.issuer
                && locals._newBalance.assetName == input.assetName
                && locals._newBalance.owner == qpi.invocator())
            {
                if (locals._newBalance.balance >= input.microTokenAmount)
                {
                    // Deduct the amount to be burned from the existing balance
                    locals._newBalance.balance -= input.microTokenAmount;
                    state._microTokenBalances.set(i, locals._newBalance);
                    locals._balanceFound = true;
                    output.burntMicroTokenAmount = input.microTokenAmount;
                }
                break;
            }
        }
    _

    struct _LockExpensiveToken_locals
    {
        
    };
    PRIVATE_PROCEDURE_WITH_LOCALS(_LockExpensiveToken)
		if (qpi.numberOfPossessedShares(input.assetName, input.issuer, qpi.invocator(), qpi.invocator(), SELF_INDEX, SELF_INDEX) < input.expensiveTokenAmount)
		{
			return;
		}
		else
		{
			qpi.transferShareOwnershipAndPossession(input.assetName, input.issuer, qpi.invocator(), qpi.invocator(), input.expensiveTokenAmount, VLIQUID_CONTRACTID);
			output.lockedExpensiveTokenAmount = input.expensiveTokenAmount;
		}
    _

    struct _UnLockExpensiveToken_locals
    {
		_BalanceOfMicroToken_input _balanceOfMicroToken_input;
		_BalanceOfMicroToken_output _balanceOfMicroToken_output;
    };
    PRIVATE_PROCEDURE_WITH_LOCALS(_UnLockExpensiveToken)
		locals._balanceOfMicroToken_input.issuer = input.issuer;
		locals._balanceOfMicroToken_input.assetName = input.assetName;
		locals._balanceOfMicroToken_input.owner = qpi.invocator();
		CALL(_BalanceOfMicroToken, locals._balanceOfMicroToken_input, locals._balanceOfMicroToken_output);
		if(locals._balanceOfMicroToken_output.balance < input.expensiveTokenAmount * MILLION)
		{
			return;
		}

		qpi.transferShareOwnershipAndPossession(input.assetName, input.issuer, VLIQUID_CONTRACTID, VLIQUID_CONTRACTID, input.expensiveTokenAmount, qpi.invocator());
		output.unLockedExpensiveTokenAmount = input.expensiveTokenAmount;
    _
    // write PUBLIC_FUNCTION
    PUBLIC_FUNCTION(ExamPublic)
        input.inputValue += 1;
        output.outputValue = input.inputValue;
    _
    // write PUBLIC_FUNCTION_WITH_LOCALS
    struct MicroTokenAllowance_locals {
        _MicroTokenAllowance _allowance;
    };
    PUBLIC_FUNCTION_WITH_LOCALS(MicroTokenAllowance)
        output.balance = 0;
        for (uint64 i = 0; i < state._microTokenAllowancesLength; i ++)
        {
            locals._allowance = state._microTokenAllowances.get(i);
            if (locals._allowance.issuer == input.issuer &&
                locals._allowance.assetName == input.assetName &&
                locals._allowance.recipient == input.recipient &&
                locals._allowance.spender == input.spender)
            {
                output.balance = locals._allowance.balance;
                break;
            }
        }
	_

	struct BalanceOfMicroToken_locals
	{
		_BalanceOfMicroToken_input _balanceOfMicroToken_input;
		_BalanceOfMicroToken_output _balanceOfMicroToken_output;
	};
	PUBLIC_FUNCTION_WITH_LOCALS(BalanceOfMicroToken)
		locals._balanceOfMicroToken_input.issuer = input.issuer;
		locals._balanceOfMicroToken_input.assetName = input.assetName;
		locals._balanceOfMicroToken_input.owner = input.owner;
		CALL(_BalanceOfMicroToken, locals._balanceOfMicroToken_input, locals._balanceOfMicroToken_output);
		output.balance = locals._balanceOfMicroToken_output.balance;
    _

    struct ApproveMicroToken_locals
    {
        bool _allowanceFound;
        _MicroTokenAllowance _newAllowance;
    };
    PUBLIC_PROCEDURE_WITH_LOCALS(ApproveMicroToken)
        if (qpi.invocationReward() > 0)
        {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
        }
        
        locals._allowanceFound = false;
        for (uint64 i = 0; i < state._microTokenAllowancesLength; i ++)
        {
            locals._newAllowance = state._microTokenAllowances.get(i);
            if (locals._newAllowance.issuer == input.issuer &&
                locals._newAllowance.assetName == input.assetName &&
                locals._newAllowance.spender == qpi.invocator() &&
                locals._newAllowance.recipient == input.recipient)
            {
                locals._newAllowance.balance = input.microTokenAmount;
                output.approvedMicroTokenAmount = input.microTokenAmount;
                locals._allowanceFound = true;
                state._microTokenAllowances.set(i, locals._newAllowance);
                break;
            }
        }
        
        if (!locals._allowanceFound)
        {
            locals._newAllowance.issuer = input.issuer;
            locals._newAllowance.assetName = input.assetName;
            locals._newAllowance.spender = qpi.invocator();
            locals._newAllowance.recipient = input.recipient;
            locals._newAllowance.balance = input.microTokenAmount;

            state._microTokenAllowances.set(state._microTokenAllowancesLength + 1, locals._newAllowance);
            state._microTokenAllowancesLength++;
            output.approvedMicroTokenAmount = input.microTokenAmount;
        }
    _

    struct TransferMicroToken_locals
    {
        bool _balanceFound;
        bool _recipientBalanceFound;
        _MicroTokenBalance _newBalance;
    };
    PUBLIC_PROCEDURE_WITH_LOCALS(TransferMicroToken)
        if (qpi.invocationReward() > 0)
        {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
        }
        output.transferredMicroTokenAmount = 0;
        locals._balanceFound = false;
        locals._recipientBalanceFound = false;
        for (uint64 i = 0; i < state._microTokenBalancesLength; i ++)
        {
            locals._newBalance = state._microTokenBalances.get(i);
            if (locals._newBalance.issuer == input.issuer &&
                locals._newBalance.assetName == input.assetName &&
                locals._newBalance.owner == qpi.invocator())
            {
                if (locals._newBalance.balance >= input.microTokenAmount)
                {
                    // Deduct the micro tokens from the invocator's balance
                    locals._newBalance.balance -= input.microTokenAmount;
                    locals._balanceFound = true;
                    state._microTokenBalances.set(i, locals._newBalance);
                }
                break;
            }
        }
        if (locals._balanceFound)
        {
            for (uint64 i = 0; i < state._microTokenBalancesLength; i ++)
            {
                locals._newBalance = state._microTokenBalances.get(i);
                if (locals._newBalance.issuer == input.issuer &&
                    locals._newBalance.assetName == input.assetName &&
                    locals._newBalance.owner == input.recipient)
                {
                    // Add the micro tokens to the recipient's balance
                    locals._newBalance.balance += input.microTokenAmount;
                    locals._recipientBalanceFound = true;
                    output.transferredMicroTokenAmount = input.microTokenAmount;
                    state._microTokenBalances.set(i, locals._newBalance);
                    break;
                }
            }

            if (!locals._recipientBalanceFound)
            {
                // If no balance entry found for the recipient, create a new one
                locals._newBalance.issuer = input.issuer;
                locals._newBalance.assetName = input.assetName;
                locals._newBalance.owner = input.recipient;
                locals._newBalance.balance = input.microTokenAmount;
                state._microTokenBalances.set(state._microTokenBalancesLength + 1, locals._newBalance);
                state._microTokenBalancesLength++;
                output.transferredMicroTokenAmount = input.microTokenAmount;
            }
        }
    _

    struct TransferFromMicroToken_locals
    {
        bool _allowanceFound;
        bool _spenderBalanceFound;
        bool _recipientBalanceFound;
        _MicroTokenBalance _newBalance;
        _MicroTokenAllowance _newAllowance;
    };
    PUBLIC_PROCEDURE_WITH_LOCALS(TransferFromMicroToken)
        if (qpi.invocationReward() > 0)
        {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
        }
        locals._allowanceFound = false;
        locals._spenderBalanceFound = false;
        locals._recipientBalanceFound = false;
        output.transferredMicroTokenAmount = 0;
        for (uint64 i = 0; i < state._microTokenAllowancesLength; i ++)
        {
            locals._newAllowance = state._microTokenAllowances.get(i);
            if (locals._newAllowance.issuer == input.issuer &&
                locals._newAllowance.assetName == input.assetName &&
                locals._newAllowance.recipient == input.recipient &&
                locals._newAllowance.spender == input.spender)
            {
                if (locals._newAllowance.balance >= input.microTokenAmount)
                {
                    // Deduct the micro tokens from the allowance
                    locals._newAllowance.balance -= input.microTokenAmount;
                    locals._allowanceFound = true;
                    state._microTokenAllowances.set(i, locals._newAllowance);
                }
                break;
            }
        }

        if (locals._allowanceFound)
        {
            for (uint64 i = 0; i < state._microTokenBalancesLength; i ++)
            {
                locals._newBalance = state._microTokenBalances.get(i);
                if (locals._newBalance.issuer == input.issuer &&
                    locals._newBalance.assetName == input.assetName &&
                    locals._newBalance.owner == input.spender)
                {
                    if (locals._newBalance.balance >= input.microTokenAmount)
                    {
                        // Deduct the micro tokens from the owner's balance
                        locals._newBalance.balance -= input.microTokenAmount;
                        locals._spenderBalanceFound = true;
                        state._microTokenBalances.set(i, locals._newBalance);
                    }
                    break;
                }
            }
            if (locals._spenderBalanceFound)
            {
                for (uint64 i = 0; i < state._microTokenBalancesLength; i ++)
                {
                    locals._newBalance = state._microTokenBalances.get(i);
                    if (locals._newBalance.issuer == input.issuer &&
                        locals._newBalance.assetName == input.assetName &&
                        locals._newBalance.owner == input.recipient)
                    {
                        // Add the micro tokens to the recipient's balance
                        locals._newBalance.balance += input.microTokenAmount;
                        locals._recipientBalanceFound = true;
                        state._microTokenBalances.set(i, locals._newBalance);
                        output.transferredMicroTokenAmount = input.microTokenAmount;
                        break;
                    }
                }
                if (!locals._recipientBalanceFound)
                {
                    // If no balance entry found for the recipient, create a new one
                    locals._newBalance.issuer = input.issuer;
                    locals._newBalance.assetName = input.assetName;
                    locals._newBalance.owner = input.recipient;
                    locals._newBalance.balance = input.microTokenAmount;
                    state._microTokenBalances.set(state._microTokenBalancesLength + 1, locals._newBalance);
                    state._microTokenBalancesLength++;
                    output.transferredMicroTokenAmount = input.microTokenAmount;
                }
            }
        }
    _

	struct ConvertToMicroToken_locals
	{
		_LockExpensiveToken_input _lockExpensiveToken_input;
		_LockExpensiveToken_output _lockExpensiveToken_output;
		_MintMicroToken_input _mintMicroToken_input;
		_MintMicroToken_output _mintMicroToken_output;
		// id _zeroIssuer;
	};
    PUBLIC_PROCEDURE_WITH_LOCALS(ConvertToMicroToken)
		if (qpi.invocationReward() > 0)
		{
			qpi.transfer(qpi.invocator(), qpi.invocationReward());
		}
		// check expensive token by name and public key
		// locals._zeroIssuer = _mm256_setzero_si256();
		// if (!_mm256_testz_si256(input.issuer, locals._zeroIssuer))
		// {
		// 	return;
		// }
		//
		if (qpi.numberOfPossessedShares(input.assetName, input.issuer, qpi.invocator(), qpi.invocator(), SELF_INDEX, SELF_INDEX) < input.expensiveTokenAmount)
		{
			return;
		}
		else
		{
			locals._lockExpensiveToken_input.issuer = input.issuer;
			locals._lockExpensiveToken_input.assetName = input.assetName;
			locals._lockExpensiveToken_input.expensiveTokenAmount = input.expensiveTokenAmount;
			CALL(_LockExpensiveToken, locals._lockExpensiveToken_input, locals._lockExpensiveToken_output);

			locals._mintMicroToken_input.issuer = input.issuer;
			locals._mintMicroToken_input.assetName = input.assetName;
			locals._mintMicroToken_input.microTokenAmount = locals._lockExpensiveToken_output.lockedExpensiveTokenAmount * MILLION;
			CALL(_MintMicroToken, locals._mintMicroToken_input, locals._mintMicroToken_output);
			output.microTokenAmount = locals._mintMicroToken_output.mintedMicroTokenAmount;
		}
    _

	struct ConvertToExpensiveToken_locals
	{
		BalanceOfMicroToken_input _balanceOfMicroToken_input;
		BalanceOfMicroToken_output _balanceOfMicroToken_output;
		_UnLockExpensiveToken_input _unLockExpensiveToken_input;
		_UnLockExpensiveToken_output _unLockExpensiveToken_output;
		_BurnMicroToken_input _burnMicroToken_input;
		_BurnMicroToken_output _burnMicroToken_output;
	};
    PUBLIC_PROCEDURE_WITH_LOCALS(ConvertToExpensiveToken)
		if (qpi.invocationReward() > 0)
		{
			qpi.transfer(qpi.invocator(), qpi.invocationReward());
		}

		locals._balanceOfMicroToken_input.issuer = input.issuer;
		locals._balanceOfMicroToken_input.assetName = input.assetName;
		locals._balanceOfMicroToken_input.owner = qpi.invocator();
		CALL(BalanceOfMicroToken, locals._balanceOfMicroToken_input, locals._balanceOfMicroToken_output);
		if (locals._balanceOfMicroToken_output.balance < input.microTokenAmount)
		{
			return;
		}
		else
		{
			locals._burnMicroToken_input.issuer = input.issuer;
			locals._burnMicroToken_input.assetName = input.assetName;
			locals._burnMicroToken_input.microTokenAmount = input.microTokenAmount;
			CALL(_BurnMicroToken, locals._burnMicroToken_input, locals._burnMicroToken_output);

			locals._unLockExpensiveToken_input.issuer = input.issuer;
			locals._unLockExpensiveToken_input.assetName = input.assetName;
			locals._unLockExpensiveToken_input.expensiveTokenAmount = locals._burnMicroToken_output.burntMicroTokenAmount / MILLION;
			CALL(_UnLockExpensiveToken, locals._unLockExpensiveToken_input, locals._unLockExpensiveToken_output);
			output.expensiveTokenAmount = locals._unLockExpensiveToken_output.unLockedExpensiveTokenAmount;
		}

    _
    
	struct CreateLiquid_locals {
		uint16 _totalWeight;
        _LiquidInfo::LiquidProvider _newProvider;
		Token _qwalletToken;
	};
	// Public procedure to create a new liquidity pool
	// This procedure handles the validation of input tokens and 
	// ensures that the initial conditions for creating a valid pool are met
	PUBLIC_PROCEDURE_WITH_LOCALS(CreateLiquid)
		if(qpi.invocationReward() < static_cast<sint64>(input.quShares + LIQUID_CREATION_FEE)) {
			// Transfer invocation reward if it's less than required quShares
			qpi.transfer(qpi.invocator(), qpi.invocationReward());
			return;
        }
        else if (qpi.invocationReward() > static_cast<sint64>(input.quShares + LIQUID_CREATION_FEE)) {
			// Transfer excess invocation reward if it's more than required quShares
			qpi.transfer(qpi.invocator(), qpi.invocationReward() - input.quShares - LIQUID_CREATION_FEE);
		}

		// Ensure the first token is QWALLET
		locals._qwalletToken = input.tokens.get(0);
        if ((locals._qwalletToken.tokenInfo.issuer != (id)QWALLET_ISSUER_ID) || (locals._qwalletToken.tokenInfo.assetName != QWALLET_TOKEN))
		{
			qpi.transfer(qpi.invocator(), qpi.invocationReward());
			return; // Error: the first token must be QWALLET
		}

		for(uint8 i = 0; i < input.tokenLength; i ++) {
			// Ensure the other tokens is not QWALLET
            if ((i > 0) && (input.tokens.get(i).tokenInfo.issuer == (id)QWALLET_ISSUER_ID) && (input.tokens.get(i).tokenInfo.assetName == QWALLET_TOKEN)) {
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
				return; // Error: other tokens can't be QWALLET
			}

			// Validate token weight (must be > 0)
			if (input.tokens.get(i).weight <= 0) {
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
				return; // Error: token weight must be greater than 0
			}

			// Validate token balance (must be > 0)
			if (input.tokens.get(i).balance <= 0) {
				qpi.transfer(qpi.invocator(), qpi.invocationReward());
				return; // Error: initial token balance must be greater than 0
			}

			// Handle MicroToken specific validations
			if(input.tokens.get(i).tokenInfo.isMicroToken)
			{
				// Ensure MicroToken allowance is sufficient compared to initial balance
				MicroTokenAllowance_input _microTokenAllowance_input{ input.tokens.get(i).tokenInfo.issuer, input.tokens.get(i).tokenInfo.assetName, VLIQUID_CONTRACTID, qpi.invocator()};
				MicroTokenAllowance_output _microTokenAllowance_output;
				CALL(MicroTokenAllowance, _microTokenAllowance_input, _microTokenAllowance_output);
				if (_microTokenAllowance_output.balance < input.tokens.get(i).balance)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
					return; // Error: insufficient MicroToken allowance
				}

				// Ensure MicroToken balance is sufficient compared to initial balance
				BalanceOfMicroToken_input _balanceOfMicroToken_input{ input.tokens.get(i).tokenInfo.issuer, input.tokens.get(i).tokenInfo.assetName, qpi.invocator()};
				BalanceOfMicroToken_output _balanceOfMicroToken_output;
                CALL(BalanceOfMicroToken, _balanceOfMicroToken_input, _balanceOfMicroToken_output);
				if(_balanceOfMicroToken_output.balance < input.tokens.get(i).balance){
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
					return; // Error: insufficient MicroToken balance
				}

			}
			else
			{
				// Ensure sufficient token shares for non-MicroTokens
                if (qpi.numberOfPossessedShares(input.tokens.get(i).tokenInfo.assetName, input.tokens.get(i).tokenInfo.issuer, qpi.invocator(), qpi.invocator(), SELF_INDEX, SELF_INDEX) < static_cast<sint64>(input.tokens.get(i).balance)) {
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
					return; // Error: insufficient token shares
				}
			}

			// Accumulate total weight of the tokens
			locals._totalWeight += input.tokens.get(i).weight;
		}

		// Validate that QWALLET's weight is greater than 10% of the total weight
		if(locals._qwalletToken.weight * 100 / locals._totalWeight < 10) {
			qpi.transfer(qpi.invocator(), qpi.invocationReward());
			return; // Error: QWALLET weight must be greater than 10%
		}

		// Initialize the first liquid provider with the invocator's contribution
        locals._newProvider.owner = qpi.invocator();
        locals._newProvider.tokenContributions = input.initialLiquid;

        state._tempLiquid.liquidProviders.set(0, locals._newProvider);

		// Execute transfer each token
		for(uint8 i = 0; i < input.tokenLength; i ++) {
			// const CreateLiquid_input::TokenInfo& _nthToken = input.tokens.get(i);

			if(input.tokens.get(i).tokenInfo.isMicroToken)
			{
				// Execute the MicroToken transfer
				TransferFromMicroToken_input _transferFromMicroToken_input{ input.tokens.get(i).tokenInfo.issuer, input.tokens.get(i).tokenInfo.assetName, qpi.invocator(), VLIQUID_CONTRACTID, input.tokens.get(i).balance};
				TransferFromMicroToken_output _transferFromMicroToken_output;

				CALL(TransferFromMicroToken, _transferFromMicroToken_input, _transferFromMicroToken_output);
                state._tempLiquid.tokens.set(i, input.tokens.get(i));
			}
			else
			{
				// Transfer ownership and possession of shares to this contract
				qpi.transferShareOwnershipAndPossession(input.tokens.get(i).tokenInfo.assetName, input.tokens.get(i).tokenInfo.issuer, qpi.invocator(), qpi.invocator(), input.tokens.get(i).balance, VLIQUID_CONTRACTID);
                // Convert ExpensiveToken to MicroToken
                ConvertToMicroToken_input _convertToMicroToken_input{ input.tokens.get(i).tokenInfo.issuer, input.tokens.get(i).tokenInfo.assetName, static_cast<sint64>(input.tokens.get(i).balance) };
                ConvertToMicroToken_output _convertToMicroToken_output;
                CALL(ConvertToMicroToken, _convertToMicroToken_input, _convertToMicroToken_output);
                state._tempLiquid.tokens.set(i, Token{ TokenInfo{input.tokens.get(i).tokenInfo.issuer, input.tokens.get(i).tokenInfo.assetName, true}, _convertToMicroToken_output.microTokenAmount, input.tokens.get(i).weight});
			}
		}

        state._tempLiquid.tokenLength = input.tokenLength;
        state._tempLiquid.quBalance = input.quShares;
        state._tempLiquid.quWeight = input.quWeight;
        state._tempLiquid.totalWeight = locals._totalWeight;
        state._tempLiquid.totalLiquid = input.initialLiquid;
        state._tempLiquid.feeRate = input.feeRate;
        state._tempLiquid.liquidProvidersCount = 1;
        state._tempLiquid.creator = qpi.invocator();
        state._tempLiquid.owner = qpi.invocator();
        state._tempLiquid.isCreated = true;

		// Store the newly created liquid pool and assign an ID
		state._liquids.set(state._liquidsCount, state._tempLiquid);
		state._liquidsCount ++;
		output.liquidId = state._liquidsCount;
	_
    
	struct AddLiquid_locals {
		uint64 _quContribution;
		_LiquidInfo::LiquidProvider _provider;
        bool _providerFound;
	};
	// Public procedure to add liquidity to an existing pool
	// This procedure validates the additional token contributions, 
	// calculates the corresponding QU contribution, and updates the liquidity.
	// It ensures the liquidity pool is valid and handles both MicroToken 
	// and regular token transfers appropriately.
    PUBLIC_PROCEDURE_WITH_LOCALS(AddLiquid)
		// Validate that the token contribution is greater than 0
		if(input.tokenContribution <= 0) {
			qpi.transfer(qpi.invocator(), qpi.invocationReward());
			return; // Error: token contribution (must be > 0)
		}

		// Retrieve the targeted liquid based on the provided ID
		state._tempLiquid = state._liquids.get(input.liquidId);
		
		// Ensure the liquid has been created
		if(!state._tempLiquid.isCreated) {
			qpi.transfer(qpi.invocator(), qpi.invocationReward());
			return; // Error: the liquid is not created
		}

		// Calculate the required QU contribution based on the input token contribution
		locals._quContribution = state._tempLiquid.quBalance * input.tokenContribution / state._tempLiquid.totalLiquid;

		// Handle the invocation reward with respect to the QU contribution
        if (qpi.invocationReward() < static_cast<sint64>(locals._quContribution)) {
			// Transfer invocation reward if it's less than required quContribution
			qpi.transfer(qpi.invocator(), qpi.invocationReward());
			return;
        }
        else if (qpi.invocationReward() > static_cast<sint64>(locals._quContribution)) {
			// Transfer excess invocation reward if it exceeds the required QU contribution
			qpi.transfer(qpi.invocator(), qpi.invocationReward() - locals._quContribution);

			state._tempLiquid.quBalance += locals._quContribution;
		}

		// Find or create a liquid provider entry for the invocator
        locals._providerFound = false;
        for (uint64 i = 0; i < state._tempLiquid.liquidProvidersCount; i++) {
            if (state._tempLiquid.liquidProviders.get(i).owner == qpi.invocator()) {
                locals._provider = state._tempLiquid.liquidProviders.get(i);
                locals._providerFound = true;
            }
        }

        if (!locals._providerFound) {
            locals._provider = _LiquidInfo::LiquidProvider{ qpi.invocator(), 0 };
            state._tempLiquid.liquidProviders.set(state._tempLiquid.liquidProvidersCount, locals._provider);
            state._tempLiquid.liquidProvidersCount++;
        }

		// Validate each token in the liquidity pool
		for(uint8 i = 0; i < state._tempLiquid.tokenLength; i ++) {
			uint64 _nthTokenContribution = state._tempLiquid.tokens.get(i).balance * input.tokenContribution / state._tempLiquid.totalLiquid;
			
			// Handle token-specific validations and transfers
			if(state._tempLiquid.tokens.get(i).tokenInfo.isMicroToken)
			{
				// Validate and transfer MicroTokens
				MicroTokenAllowance_input _microTokenAllowance_input{ state._tempLiquid.tokens.get(i).tokenInfo.issuer, state._tempLiquid.tokens.get(i).tokenInfo.assetName, VLIQUID_CONTRACTID, qpi.invocator()};
				MicroTokenAllowance_output _microTokenAllowance_output;
				CALL(MicroTokenAllowance, _microTokenAllowance_input, _microTokenAllowance_output);
				if (_microTokenAllowance_output.balance < _nthTokenContribution)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
					return; // Error: insufficient MicroToken allowance
				}
				
				// Ensure MicroToken balance is sufficient compared to initial balance
				BalanceOfMicroToken_input _balanceOfMicroToken_input{ state._tempLiquid.tokens.get(i).tokenInfo.issuer, state._tempLiquid.tokens.get(i).tokenInfo.assetName, qpi.invocator()};
				BalanceOfMicroToken_output _balanceOfMicroToken_output;
                CALL(BalanceOfMicroToken, _balanceOfMicroToken_input, _balanceOfMicroToken_output);
				if(_balanceOfMicroToken_output.balance < _nthTokenContribution){
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
					return; // Error: insufficient MicroToken balance
				}
			
				// Update the token balance in the liquid
                state._tempLiquid.tokens.set(i, Token{state._tempLiquid.tokens.get(i).tokenInfo, state._tempLiquid.tokens.get(i).balance + _nthTokenContribution, state._tempLiquid.tokens.get(i).weight});
			}
			else
			{
				// Ensure sufficient token shares for non-MicroTokens
                if (qpi.numberOfPossessedShares(state._tempLiquid.tokens.get(i).tokenInfo.assetName, state._tempLiquid.tokens.get(i).tokenInfo.issuer, qpi.invocator(), qpi.invocator(), SELF_INDEX, SELF_INDEX) < static_cast<sint64>(_nthTokenContribution)) {
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
					return; // Error: insufficient token shares
				}

				// Update the token balance in the liquid
                state._tempLiquid.tokens.set(i, Token{ state._tempLiquid.tokens.get(i).tokenInfo, state._tempLiquid.tokens.get(i).balance + _nthTokenContribution * MILLION, state._tempLiquid.tokens.get(i).weight });
			}
            // locals._liquid.tokens.set(i, locals._nthToken);
		}

		// Execute transfer each token
		for(uint8 i = 0; i < state._tempLiquid.tokenLength; i ++) {
			// const _LiquidInfo::TokenInfo& _nthToken = locals._liquid.tokens.get(i);
			uint64 _nthTokenContribution = state._tempLiquid.tokens.get(i).balance * input.tokenContribution / state._tempLiquid.totalLiquid;
			
			// Handle token-specific validations and transfers
			if(state._tempLiquid.tokens.get(i).tokenInfo.isMicroToken)
			{
				// Execute the MicroToken transfer
				TransferFromMicroToken_input _transferFromMicroToken_input{ state._tempLiquid.tokens.get(i).tokenInfo.issuer, state._tempLiquid.tokens.get(i).tokenInfo.assetName, qpi.invocator(), VLIQUID_CONTRACTID, _nthTokenContribution};
				TransferFromMicroToken_output _transferFromMicroToken_output;

				CALL(TransferFromMicroToken, _transferFromMicroToken_input, _transferFromMicroToken_output);
			}
			else
			{
				// Transfer ownership and possession of shares to this contract
				qpi.transferShareOwnershipAndPossession(state._tempLiquid.tokens.get(i).tokenInfo.assetName, state._tempLiquid.tokens.get(i).tokenInfo.issuer, qpi.invocator(), qpi.invocator(), _nthTokenContribution / MILLION, VLIQUID_CONTRACTID);
			}
		}

		// Update the liquid provider's contributions and the total liquidity of the liquid
		locals._provider.tokenContributions += input.tokenContribution;
		state._tempLiquid.totalLiquid += input.tokenContribution;
		state._liquids.set(input.liquidId, state._tempLiquid);
		output.addedContribution = input.tokenContribution;
    _
    
	struct RemoveLiquid_locals {
		_LiquidInfo::LiquidProvider _provider;
        _LiquidInfo::LiquidProvider _lastProvider;
        uint64 _removedBalance;
        bool _providerFound;
	};
    PUBLIC_PROCEDURE_WITH_LOCALS(RemoveLiquid)
		// Retrieve the targeted liquid based on the provided ID
		state._tempLiquid = state._liquids.get(input.liquidId);
		
		// Find the provider associated with the invocator
		// locals._provider = _findProvder(locals._liquid, qpi.invocator());
        locals._providerFound = false;
        for (uint64 i = 0; i < state._tempLiquid.liquidProvidersCount; i++) {
            locals._provider = state._tempLiquid.liquidProviders.get(i);
            if (locals._provider.owner == qpi.invocator()) {
                locals._providerFound = true;
            }
        }
		// Check if the participant exists
		if (!locals._providerFound) {
			if(qpi.invocationReward() > 0) {
                qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return; // Error: Participant not found
		}

		// Check if the provider's contribution is sufficient
		if(locals._provider.tokenContributions < input.tokenContribution) {
			if(qpi.invocationReward() > 0) {
                qpi.transfer(qpi.invocator(), qpi.invocationReward());
			}
			return; // Error: Insufficient token contribution
		}

		// Calculate and transfer the corresponding QU tokens to the invocator
		// QU transfer
		uint64 _removedQuBalance = state._tempLiquid.quBalance * input.tokenContribution / state._tempLiquid.totalLiquid;
		qpi.transfer(qpi.invocator(), _removedQuBalance);
        state._tempLiquid.quBalance -= _removedQuBalance;

		// Process each token in the liquid pool
		// Token transfer
		for(uint8 i = 0; i < state._tempLiquid.tokenLength; i ++) {
			// Calculate the micro token amount of tokens to remove
			locals._removedBalance = state._tempLiquid.tokens.get(i).balance * input.tokenContribution / state._tempLiquid.totalLiquid;

			TransferMicroToken_input _transferMicroToken_input{ state._tempLiquid.tokens.get(i).tokenInfo.issuer, state._tempLiquid.tokens.get(i).tokenInfo.assetName, VLIQUID_CONTRACTID, locals._removedBalance};
			TransferMicroToken_output _transferMicroToken_output;
			CALL(TransferMicroToken, _transferMicroToken_input, _transferMicroToken_output);

			// Update the micro token balance in the liquid pool

            state._tempLiquid.tokens.set(i, Token{ state._tempLiquid.tokens.get(i).tokenInfo, state._tempLiquid.tokens.get(i).balance - locals._removedBalance, state._tempLiquid.tokens.get(i).weight });
		}

		// Update the provider's contribution and the total liquid in the pool
		locals._provider.tokenContributions -= input.tokenContribution;
		state._tempLiquid.totalLiquid -= input.tokenContribution;

		// If the provider has withdrawn all contributions, remove them from the poroviders list
		if (locals._provider.tokenContributions == 0) {
			// _removeProvider(locals._liquid, qpi.invocator());
            for (uint64 i = 0; i < state._tempLiquid.liquidProvidersCount; i++) {
                locals._provider = state._tempLiquid.liquidProviders.get(i);

                if (locals._provider.owner == qpi.invocator()) {
                    if (i == state._tempLiquid.liquidProvidersCount - 1) {
                        state._tempLiquid.liquidProvidersCount--;
                    }
                    else {
                        locals._lastProvider = state._tempLiquid.liquidProviders.get(state._tempLiquid.liquidProvidersCount - 1);
                        state._tempLiquid.liquidProviders.set(i, locals._lastProvider);
                        state._tempLiquid.liquidProvidersCount--;
                    }
                }
            }
		}

		// Save the updated liquid state
		state._liquids.set(input.liquidId, state._tempLiquid);

		output.removedContribution = input.tokenContribution;
    _
    struct SwapToQU_locals {
        uint64 _reserveToken;
        uint64 _reserveQU;
        uint64 _weightToken;
        uint64 _weightQU;
        uint64 _price;
        uint64 _outputQUAmount;
        uint8 _inputTokenIndex;
    };
    PUBLIC_PROCEDURE_WITH_LOCALS(SwapToQU)
        // Validate the input token amount
        MicroTokenAllowance_input _microTokenAllowance_input{ input.inputTokenInfo.issuer, input.inputTokenInfo.assetName, VLIQUID_CONTRACTID, qpi.invocator()};
        MicroTokenAllowance_output _microTokenAllowance_output;
        CALL(MicroTokenAllowance, _microTokenAllowance_input, _microTokenAllowance_output);
        if(_microTokenAllowance_output.balance < input.inputAmount) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return; // Error: Insufficient token allowance
        }

        // Retrieve the liquid pool based on the provided ID
        state._tempLiquid = state._liquids.get(input.liquidId);

        locals._reserveToken = 0;
        locals._reserveQU = state._tempLiquid.quBalance;
        locals._weightToken = 0;
        locals._weightQU = state._tempLiquid.quWeight;

        for (uint8 i = 0; i < state._tempLiquid.tokenLength; i++) {
            if((state._tempLiquid.tokens.get(i).tokenInfo.issuer == input.inputTokenInfo.issuer) && 
            (state._tempLiquid.tokens.get(i).tokenInfo.assetName == input.inputTokenInfo.assetName)) {
                locals._reserveToken = state._tempLiquid.tokens.get(i).balance;
                locals._weightToken = state._tempLiquid.tokens.get(i).weight;
                locals._inputTokenIndex = i;
                break;
            }
        }

        if(locals._reserveToken == 0 || locals._weightToken == 0) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return; // Error: Invalid token
        }

        // Calculate the price of the token in terms of QU
        locals._price = (locals._reserveToken * locals._weightToken * MILLION) / (locals._reserveQU * locals._weightQU);
        // Calculate the output QU amount
        locals._outputQUAmount = input.inputAmount * locals._price / MILLION;

        // Transfer the output QU amount to the invocator
        qpi.transfer(qpi.invocator(), locals._outputQUAmount);

        // Update the token and QU reserves
        state._tempLiquid.tokens.set(locals._inputTokenIndex, Token{ state._tempLiquid.tokens.get(locals._inputTokenIndex).tokenInfo, state._tempLiquid.tokens.get(locals._inputTokenIndex).balance + input.inputAmount, state._tempLiquid.tokens.get(locals._inputTokenIndex).weight });
        state._tempLiquid.quBalance -= locals._outputQUAmount;

        // Save the updated liquid state
        state._liquids.set(input.liquidId, state._tempLiquid);

        output.quAmount = locals._outputQUAmount;
    _
    struct SwapFromQU_locals {
        uint64 _reserveToken;
        uint64 _reserveQU;
        uint8 _weightToken;
        uint8 _weightQU;
        uint64 _price;
        uint64 _outputTokenAmount;
        uint8 _outputTokenIndex;
    };
    PUBLIC_PROCEDURE_WITH_LOCALS(SwapFromQU)
        // Validate the input QU amount
        if (input.quAmount <= qpi.invocationReward() || input.quAmount > state._tempLiquid.quBalance) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return; // Error: Invalid QU amount
        }

        // Return the excess QU amount to the invocator
        if(input.quAmount > qpi.invocationReward()) {
            qpi.transfer(qpi.invocator(), input.quAmount - qpi.invocationReward());
        }

        // Retrieve the liquid pool based on the provided ID
        state._tempLiquid = state._liquids.get(input.liquidId);

        locals._reserveToken = 0;
        locals._reserveQU = state._tempLiquid.quBalance;
        locals._weightToken = 0;
        locals._weightQU = state._tempLiquid.quWeight;

        for (uint8 i = 0; i < state._tempLiquid.tokenLength; i++) {
            if((state._tempLiquid.tokens.get(i).tokenInfo.issuer == input.outputTokenInfo.issuer) && 
            (state._tempLiquid.tokens.get(i).tokenInfo.assetName == input.outputTokenInfo.assetName)) {
                locals._reserveToken = state._tempLiquid.tokens.get(i).balance;
                locals._weightToken = state._tempLiquid.tokens.get(i).weight;
                locals._outputTokenIndex = i;
                break;
            }
        }

        if(locals._reserveToken == 0 || locals._weightToken == 0) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return; // Error: Invalid token
        }

        // Calculate the price of QU in terms of the token
        locals._price = (locals._reserveQU * locals._weightQU * MILLION) / (locals._reserveToken * locals._weightToken);
        // Calculate the output token amount
        locals._outputTokenAmount = input.quAmount * locals._price / MILLION;

        // Transfer the output token amount to the invocator
        TransferMicroToken_input _transferMicroToken_input{ input.outputTokenInfo.issuer, input.outputTokenInfo.assetName, VLIQUID_CONTRACTID, locals._outputTokenAmount};
        TransferMicroToken_output _transferMicroToken_output;
        CALL(TransferMicroToken, _transferMicroToken_input, _transferMicroToken_output);

        // Update the token and QU reserves
        state._tempLiquid.tokens.set(locals._outputTokenIndex, Token{ state._tempLiquid.tokens.get(locals._outputTokenIndex).tokenInfo, state._tempLiquid.tokens.get(locals._outputTokenIndex).balance - locals._outputTokenAmount, state._tempLiquid.tokens.get(locals._outputTokenIndex).weight });
        state._tempLiquid.quBalance += input.quAmount;

        // Save the updated liquid state
        state._liquids.set(input.liquidId, state._tempLiquid);

        output.outputAmount = locals._outputTokenAmount;
    _
    struct SwapToQwallet_locals {
        uint64 _reserveToken;
        uint64 _reserveQwallet;
        uint8 _weightToken;
        uint8 _weightQwallet;
        uint64 _price;
        uint64 _outputQwalletAmount;
        uint64 _outputQuAmount;
        uint64 _remainder;
        uint64 _quPrice;
        uint8 _inputTokenIndex;
    };
    PUBLIC_PROCEDURE_WITH_LOCALS(SwapToQwallet)
        // Validate the input token amount
        MicroTokenAllowance_input _microTokenAllowance_input{ input.inputTokenInfo.issuer, input.inputTokenInfo.assetName, VLIQUID_CONTRACTID, qpi.invocator()};
        MicroTokenAllowance_output _microTokenAllowance_output;
        CALL(MicroTokenAllowance, _microTokenAllowance_input, _microTokenAllowance_output);
        if(_microTokenAllowance_output.balance < input.inputAmount) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return; // Error: Insufficient token allowance
        }

        // Retrieve the liquid pool based on the provided ID
        state._tempLiquid = state._liquids.get(input.liquidId);

        locals._reserveToken = 0;
        locals._reserveQwallet = state._tempLiquid.tokens.get(0).balance;
        locals._weightToken = 0;
        locals._weightQwallet = state._tempLiquid.tokens.get(0).weight;

        for (uint8 i = 0; i < state._tempLiquid.tokenLength; i++) {
            if((state._tempLiquid.tokens.get(i).tokenInfo.issuer == input.inputTokenInfo.issuer) && 
            (state._tempLiquid.tokens.get(i).tokenInfo.assetName == input.inputTokenInfo.assetName)) {
                locals._reserveToken = state._tempLiquid.tokens.get(i).balance;
                locals._weightToken = state._tempLiquid.tokens.get(i).weight;
                locals._inputTokenIndex = i;
                break;
            }
        }

        if(locals._reserveToken == 0 || locals._weightToken == 0) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return; // Error: Invalid token
        }

        // Calculate the price of the token in terms of Qwallet
        locals._price = (locals._reserveToken * locals._weightToken * MILLION) / (locals._reserveQwallet * locals._weightQwallet);
        // Calculate the output Qwallet amount and remainder
        locals._outputQwalletAmount = (input.inputAmount * locals._price) / MILLION;
        locals._remainder = (input.inputAmount * locals._price) % MILLION;

        // Calculate the output QU amount from the remainder
        locals._quPrice = (state._tempLiquid.quBalance * state._tempLiquid.quWeight * MILLION) / (state._tempLiquid.tokens.get(0).balance * state._tempLiquid.tokens.get(0).weight);
        locals._outputQuAmount = (locals._remainder * locals._quPrice) / MILLION / MILLION;

        // Transfer the output Qwallet amount to the invocator
        TransferMicroToken_input _transferMicroToken_input{ state._tempLiquid.tokens.get(0).tokenInfo.issuer, state._tempLiquid.tokens.get(0).tokenInfo.assetName, VLIQUID_CONTRACTID, locals._outputQwalletAmount};
        TransferMicroToken_output _transferMicroToken_output;
        CALL(TransferMicroToken, _transferMicroToken_input, _transferMicroToken_output);

        // Transfer the output QU amount to the invocator
        qpi.transfer(qpi.invocator(), locals._outputQuAmount);

        // Update the token and Qwallet reserves
        state._tempLiquid.tokens.set(locals._inputTokenIndex, Token{ state._tempLiquid.tokens.get(locals._inputTokenIndex).tokenInfo, state._tempLiquid.tokens.get(locals._inputTokenIndex).balance + input.inputAmount, state._tempLiquid.tokens.get(locals._inputTokenIndex).weight });
        state._tempLiquid.tokens.set(0, Token{ state._tempLiquid.tokens.get(0).tokenInfo, state._tempLiquid.tokens.get(0).balance - locals._outputQwalletAmount, state._tempLiquid.tokens.get(0).weight });
        state._tempLiquid.quBalance -= locals._outputQuAmount;

        // Save the updated liquid state
        state._liquids.set(input.liquidId, state._tempLiquid);

        output.qwalletAmount = locals._outputQwalletAmount;
        output.quAmount = locals._outputQuAmount;
    _
    struct SwapFromQwallet_locals {
        uint64 _reserveToken;
        uint64 _reserveQwallet;
        uint8 _weightToken;
        uint8 _weightQwallet;
        uint64 _price;
        uint64 _outputTokenAmount;
        uint64 _remainder;
        uint64 _outputQuAmount;
        uint64 _quPrice;
        Token _token;
        uint8 _outputTokenIndex;
    };
    PUBLIC_PROCEDURE_WITH_LOCALS(SwapFromQwallet)
        // Validate the input Qwallet amount
        if (input.qwalletAmount <= 0 || input.qwalletAmount > state._tempLiquid.tokens.get(0).balance) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return; // Error: Invalid Qwallet amount
        }

        // Retrieve the liquid pool based on the provided ID
        state._tempLiquid = state._liquids.get(input.liquidId);

        MicroTokenAllowance_input _microTokenAllowance_input{ state._tempLiquid.tokens.get(0).tokenInfo.issuer, state._tempLiquid.tokens.get(0).tokenInfo.assetName, VLIQUID_CONTRACTID, qpi.invocator()};
        MicroTokenAllowance_output _microTokenAllowance_output;
        CALL(MicroTokenAllowance, _microTokenAllowance_input, _microTokenAllowance_output);
        if(_microTokenAllowance_output.balance < input.qwalletAmount) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return; // Error: Insufficient Qwallet allowance
        }

        locals._reserveToken = 0;
        locals._reserveQwallet = state._tempLiquid.tokens.get(0).balance;
        locals._weightToken = 0;
        locals._weightQwallet = state._tempLiquid.tokens.get(0).weight;

        for (uint8 i = 0; i < state._tempLiquid.tokenLength; i++) {
            if((state._tempLiquid.tokens.get(i).tokenInfo.issuer == input.outputTokenInfo.issuer) && 
            (state._tempLiquid.tokens.get(i).tokenInfo.assetName == input.outputTokenInfo.assetName)) {
                locals._reserveToken = state._tempLiquid.tokens.get(i).balance;
                locals._weightToken = state._tempLiquid.tokens.get(i).weight;
                locals._token = state._tempLiquid.tokens.get(i);
                locals._outputTokenIndex = i;
                break;
            }
        }

        if(locals._reserveToken == 0 || locals._weightToken == 0) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return; // Error: Invalid token
        }

        // Calculate the price of Qwallet in terms of the token
        locals._price = (locals._reserveQwallet * locals._weightQwallet * MILLION) / (locals._reserveToken * locals._weightToken);
        // Calculate the output token amount and remainder
        locals._outputTokenAmount = (input.qwalletAmount * locals._price) / MILLION;
        locals._remainder = (input.qwalletAmount * locals._price) % MILLION;

        // Calculate the output QU amount from the remainder
        locals._quPrice = (state._tempLiquid.quBalance * state._tempLiquid.quWeight * MILLION) / (locals._token.balance * locals._token.weight);
        locals._outputQuAmount = (locals._remainder * locals._quPrice) / MILLION / MILLION;

        // Transfer the output token amount to the invocator
        TransferMicroToken_input _transferMicroToken_input{ input.outputTokenInfo.issuer, input.outputTokenInfo.assetName, VLIQUID_CONTRACTID, locals._outputTokenAmount};
        TransferMicroToken_output _transferMicroToken_output;
        CALL(TransferMicroToken, _transferMicroToken_input, _transferMicroToken_output);

        // Transfer the output QU amount to the invocator
        qpi.transfer(qpi.invocator(), locals._outputQuAmount);

        // Update the token and Qwallet reserves
        state._tempLiquid.tokens.set(locals._outputTokenIndex, Token{ state._tempLiquid.tokens.get(locals._outputTokenIndex).tokenInfo, state._tempLiquid.tokens.get(locals._outputTokenIndex).balance - locals._outputTokenAmount, state._tempLiquid.tokens.get(locals._outputTokenIndex).weight });
        state._tempLiquid.tokens.set(0, Token{ state._tempLiquid.tokens.get(0).tokenInfo, state._tempLiquid.tokens.get(0).balance + input.qwalletAmount, state._tempLiquid.tokens.get(0).weight });
        state._tempLiquid.quBalance -= locals._outputQuAmount;

        // Save the updated liquid state
        state._liquids.set(input.liquidId, state._tempLiquid);

        output.outputAmount = locals._outputTokenAmount;
        output.quAmount = locals._outputQuAmount;
    _
    struct SwapQUToQwallet_locals {
        uint64 _reserveQwallet;
        uint64 _reserveQU;
        uint8 _weightQwallet;
        uint8 _weightQU;
        uint64 _price;
        uint64 _outputQwalletAmount;
    };
    PUBLIC_PROCEDURE_WITH_LOCALS(SwapQUToQwallet)
        // Validate the input QU amount
        if (input.quAmount <= 0 || input.quAmount > state._tempLiquid.quBalance) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return; // Error: Invalid QU amount
        }

        // Return the excess QU amount to the invocator
        if (input.quAmount > qpi.invocationReward()) {
            qpi.transfer(qpi.invocator(), input.quAmount - qpi.invocationReward());
        }

        // Retrieve the liquid pool based on the provided ID
        state._tempLiquid = state._liquids.get(input.liquidId);

        locals._reserveQwallet = state._tempLiquid.tokens.get(0).balance;
        locals._reserveQU = state._tempLiquid.quBalance;
        locals._weightQwallet = state._tempLiquid.tokens.get(0).weight;
        locals._weightQU = state._tempLiquid.quWeight;

        // Calculate the price of QU in terms of Qwallet
        locals._price = (locals._reserveQU * locals._weightQU * MILLION) / (locals._reserveQwallet * locals._weightQwallet);
        // Calculate the output Qwallet amount
        locals._outputQwalletAmount = input.quAmount * locals._price / MILLION;

        // Transfer the output Qwallet amount to the invocator
        TransferMicroToken_input _transferMicroToken_input{ state._tempLiquid.tokens.get(0).tokenInfo.issuer, state._tempLiquid.tokens.get(0).tokenInfo.assetName, VLIQUID_CONTRACTID, locals._outputQwalletAmount};
        TransferMicroToken_output _transferMicroToken_output;
        CALL(TransferMicroToken, _transferMicroToken_input, _transferMicroToken_output);

        // Update the Qwallet and QU reserves
        state._tempLiquid.tokens.set(0, Token{ state._tempLiquid.tokens.get(0).tokenInfo, state._tempLiquid.tokens.get(0).balance - locals._outputQwalletAmount, state._tempLiquid.tokens.get(0).weight });
        state._tempLiquid.quBalance += input.quAmount;

        // Save the updated liquid state
        state._liquids.set(input.liquidId, state._tempLiquid);

        output.qwalletAmount = locals._outputQwalletAmount;
    _
    struct SwapQwalletToQU_locals {
        uint64 _reserveQwallet;
        uint64 _reserveQU;
        uint8 _weightQwallet;
        uint8 _weightQU;
        uint64 _price;
        uint64 _outputQuAmount;
    };
    PUBLIC_PROCEDURE_WITH_LOCALS(SwapQwalletToQU)
        // Validate the input Qwallet amount
        if (input.qwalletAmount <= 0 || input.qwalletAmount > state._tempLiquid.tokens.get(0).balance) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return; // Error: Invalid Qwallet amount
        }

        // Retrieve the liquid pool based on the provided ID
        state._tempLiquid = state._liquids.get(input.liquidId);

        locals._reserveQwallet = state._tempLiquid.tokens.get(0).balance;
        locals._reserveQU = state._tempLiquid.quBalance;
        locals._weightQwallet = state._tempLiquid.tokens.get(0).weight;
        locals._weightQU = state._tempLiquid.quWeight;

        // Calculate the price of Qwallet in terms of QU
        locals._price = (locals._reserveQwallet * locals._weightQwallet * MILLION) / (locals._reserveQU * locals._weightQU);
        // Calculate the output QU amount
        locals._outputQuAmount = input.qwalletAmount * locals._price / MILLION;

        // Transfer the output QU amount to the invocator
        qpi.transfer(qpi.invocator(), locals._outputQuAmount);

        // Update the Qwallet and QU reserves
        state._tempLiquid.tokens.set(0, Token{ state._tempLiquid.tokens.get(0).tokenInfo, state._tempLiquid.tokens.get(0).balance - input.qwalletAmount, state._tempLiquid.tokens.get(0).weight });
        state._tempLiquid.quBalance += locals._outputQuAmount;

        // Save the updated liquid state
        state._liquids.set(input.liquidId, state._tempLiquid);

        output.quAmount = locals._outputQuAmount;
    _
    struct SingleSwap_locals {
        uint64 _reserveA;
        uint64 _reserveB;
        uint8 _weightA;
        uint8 _weightB;
        uint64 _price;
        uint64 _qwalletPrice;
        uint64 _quPrice;
        uint64 _outputAmount;
        uint64 _outputQwalletPromisedAmount;
        uint64 _outputQwalletAmount;
        uint64 _outputQuPromisedAmount;
        uint64 _outputQuAmount;
        uint8 _inputTokenIndex;
        uint8 _outputTokenIndex;
    };
    PUBLIC_PROCEDURE_WITH_LOCALS(SingleSwap)
        // Validate the input token amount
        MicroTokenAllowance_input _microTokenAllowance_input{ input.inputTokenInfo.issuer, input.inputTokenInfo.assetName, VLIQUID_CONTRACTID, qpi.invocator()};
        MicroTokenAllowance_output _microTokenAllowance_output;
        CALL(MicroTokenAllowance, _microTokenAllowance_input, _microTokenAllowance_output);
        if(_microTokenAllowance_output.balance < input.inputAmount) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return; // Error: Insufficient token allowance
        }

        // Retrieve the liquid pool based on the provided ID
        state._tempLiquid = state._liquids.get(input.liquidId);

        locals._reserveA = 0;
        locals._reserveB = 0;
        locals._weightA = 0;
        locals._weightB = 0;

        for (uint8 i = 0; i < state._tempLiquid.tokenLength; i++) {
            if((state._tempLiquid.tokens.get(i).tokenInfo.issuer == input.inputTokenInfo.issuer) && (state._tempLiquid.tokens.get(i).tokenInfo.issuer == input.inputTokenInfo.issuer))
            {
                locals._reserveA = state._tempLiquid.tokens.get(i).balance;
                locals._weightA = state._tempLiquid.tokens.get(i).weight;
                locals._inputTokenIndex = i;
            }
            else if((state._tempLiquid.tokens.get(i).tokenInfo.issuer == input.outputTokenInfo.issuer) && (state._tempLiquid.tokens.get(i).tokenInfo.issuer == input.outputTokenInfo.issuer))
            {
                locals._reserveB = state._tempLiquid.tokens.get(i).balance;
                locals._weightB = state._tempLiquid.tokens.get(i).weight;
                locals._outputTokenIndex = i;
            }
        }

        if(locals._reserveA == 0 || locals._reserveB == 0 || locals._weightA == 0 || locals._weightB == 0) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return; // Error: Invalid token pair
        }

        // Calculate the price of the token in terms of the other token
        locals._price = (locals._reserveA * locals._weightA * MILLION) / (locals._reserveB * locals._weightB);
        // Calculate the output amount
        locals._outputAmount = input.inputAmount * locals._price / MILLION;
        locals._outputQwalletPromisedAmount = input.inputAmount * locals._price % MILLION;

        locals._qwalletPrice = (state._tempLiquid.tokens.get(0).balance * state._tempLiquid.tokens.get(0).weight * MILLION) / (locals._reserveB * locals._weightA);
        locals._outputQwalletAmount = locals._outputQwalletPromisedAmount * locals._qwalletPrice / MILLION / MILLION;

        locals._outputQuPromisedAmount = locals._outputQwalletPromisedAmount * locals._qwalletPrice % MILLION;
        locals._quPrice = (state._tempLiquid.quBalance * state._tempLiquid.quWeight * MILLION) / (state._tempLiquid.tokens.get(0).balance * state._tempLiquid.tokens.get(0).weight);
        locals._outputQuAmount = locals._outputQuPromisedAmount * locals._quPrice / MILLION / MILLION;

        // Transfer the output amount of tokenOut to the invocator
        TransferMicroToken_input _transferMicroToken_input{ state._tempLiquid.tokens.get(locals._outputTokenIndex).tokenInfo.issuer, state._tempLiquid.tokens.get(locals._outputTokenIndex).tokenInfo.assetName, VLIQUID_CONTRACTID, locals._outputAmount};
        TransferMicroToken_output _transferMicroToken_output;
        CALL(TransferMicroToken, _transferMicroToken_input, _transferMicroToken_output);

        // TransferFrom the input amount of tokenA to this contract
        TransferFromMicroToken_input _transferFromMicroToken_input{
            state._tempLiquid.tokens.get(locals._inputTokenIndex).tokenInfo.issuer,
            state._tempLiquid.tokens.get(locals._inputTokenIndex).tokenInfo.assetName,
            qpi.invocator(),
            VLIQUID_CONTRACTID,
            input.inputAmount
        };
        TransferFromMicroToken_output _transferFromMicroToken_output;
        CALL(TransferFromMicroToken, _transferFromMicroToken_input, _transferFromMicroToken_output);

        // Transfer Qwallet
        TransferMicroToken_input _transferQwalletMicroToken_input{ state._tempLiquid.tokens.get(0).tokenInfo.issuer, state._tempLiquid.tokens.get(0).tokenInfo.assetName, VLIQUID_CONTRACTID, locals._outputQwalletAmount};
        TransferMicroToken_output _transferQwalletMicroToken_output;
        CALL(TransferMicroToken, _transferQwalletMicroToken_input, _transferQwalletMicroToken_output);

        // Transfer QU
        qpi.transfer(qpi.invocator(), locals._outputQuAmount);

        // Update the token reserves
        state._tempLiquid.tokens.set(locals._outputTokenIndex, Token{ state._tempLiquid.tokens.get(locals._outputTokenIndex).tokenInfo, state._tempLiquid.tokens.get(locals._outputTokenIndex).balance - locals._outputAmount, state._tempLiquid.tokens.get(locals._outputTokenIndex).weight });

        state._tempLiquid.tokens.set(locals._inputTokenIndex, Token{ state._tempLiquid.tokens.get(locals._inputTokenIndex).tokenInfo, state._tempLiquid.tokens.get(locals._inputTokenIndex).balance + input.inputAmount, state._tempLiquid.tokens.get(locals._inputTokenIndex).weight });
        
        state._tempLiquid.tokens.set(0, Token{ state._tempLiquid.tokens.get(0).tokenInfo, state._tempLiquid.tokens.get(0).balance - locals._outputQwalletAmount, state._tempLiquid.tokens.get(0).weight });
        state._tempLiquid.quBalance -= locals._outputQuAmount;

        // Save the updated liquid state
        state._liquids.set(input.liquidId, state._tempLiquid);

        output.outputAmount = locals._outputAmount;
        output.outputQwalletAmount = locals._outputQwalletAmount;
        output.outputQuAmount = locals._outputQuAmount;
    _

    struct CrossSwap_locals {
        SwapToQwallet_input _swapToQwallet_input;
        SwapToQwallet_output _swapToQwallet_output;
        SwapFromQwallet_input _swapFromQwallet_input;
        SwapFromQwallet_output _swapFromQwallet_output;
    };

    PUBLIC_PROCEDURE_WITH_LOCALS(CrossSwap)
        // Validate the input token amount
        MicroTokenAllowance_input _microTokenAllowance_input{ input.inputTokenInfoA.issuer, input.inputTokenInfoA.assetName, VLIQUID_CONTRACTID, qpi.invocator()};
        MicroTokenAllowance_output _microTokenAllowance_output;
        CALL(MicroTokenAllowance, _microTokenAllowance_input, _microTokenAllowance_output);
        if(_microTokenAllowance_output.balance < input.inputAmountA) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return; // Error: Insufficient token allowance
        }
    
        // Step 1: Swap token A to Qwallet in liquid A
        locals._swapToQwallet_input.liquidId = input.liquidIdA;
        locals._swapToQwallet_input.inputTokenInfo = input.inputTokenInfoA;
        locals._swapToQwallet_input.inputAmount = input.inputAmountA;
        CALL(SwapToQwallet, locals._swapToQwallet_input, locals._swapToQwallet_output);

        // Step 2: Swap Qwallet to token B in liquid B
        locals._swapFromQwallet_input.liquidId = input.liquidIdB;
        locals._swapFromQwallet_input.outputTokenInfo = input.outputTokenInfoB;
        locals._swapFromQwallet_input.qwalletAmount = locals._swapToQwallet_output.qwalletAmount;
        CALL(SwapFromQwallet, locals._swapFromQwallet_input, locals._swapFromQwallet_output);

        // Set the output values
        output.outputAmountB = locals._swapFromQwallet_output.outputAmount;
        output.outputQwalletAmount = locals._swapToQwallet_output.qwalletAmount;
        output.outputQuAmount = locals._swapFromQwallet_output.quAmount + locals._swapToQwallet_output.quAmount;
    _
    struct InitializeStakingPool_locals {
    };
    PUBLIC_PROCEDURE_WITH_LOCALS(InitializeStakingPool)
        state._tempLiquid = state._liquids.get(input.liquidId);

        // if liquid was not created, return invocation reward and exit
        if(!state._tempLiquid.isCreated) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return;
        }

        // validate if the invocator is liquid owner
        if(state._tempLiquid.owner != qpi.invocator()) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return;
        }
        
        state._tempStakingPool.liquidId = input.liquidId;
        state._tempStakingPool.totalStaked = 0;
        state._tempStakingPool.totalBonusTokenAmount = 0;
        state._tempStakingPool.accPerShare = 0;
        state._tempStakingPool.lastRewardTick= qpi.tick();
        state._tempStakingPool.isInitialized = true;
        state._tempStakingPool.stakerCount = 0;
        state._tempStakingPool.bonusTokenInfo = input.bonusTokenInfo;

        state._stakingPools.set(input.liquidId, state._tempStakingPool);
        state._stakingPoolsCount++;
        output.success = true;
    _
    struct DepositeBonusToken_locals {

    };
    PUBLIC_PROCEDURE_WITH_LOCALS(DepositeBonusToken)
        // Retrieve the staking pool based on the provided liquid ID
        state._tempStakingPool = state._stakingPools.get(input.liquidId);

        // Check if the staking pool is initialized
        if (!state._tempStakingPool.isInitialized) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return; // Error: Staking pool not initialized
        }

        // Validate the bonus token amount
        if (input.bonusTokenAmount <= 0) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return; // Error: Invalid bonus token amount
        }

        // Transfer the bonus tokens to the staking pool
        TransferMicroToken_input _transferMicroToken_input{ 
            state._tempStakingPool.bonusTokenInfo.issuer,
            state._tempStakingPool.bonusTokenInfo.assetName,
            VLIQUID_CONTRACTID,
            input.bonusTokenAmount
        };
        TransferMicroToken_output _transferMicroToken_output;
        CALL(TransferMicroToken, _transferMicroToken_input, _transferMicroToken_output);

        // Update the total bonus token amount in the staking pool
        state._tempStakingPool.totalBonusTokenAmount += input.bonusTokenAmount;

        // Save the updated staking pool state
        state._stakingPools.set(input.liquidId, state._tempStakingPool);
    _
    struct Stake_locals {
        uint64 _rewardDebt;
        uint64 _reward;
        uint64 _providerIndex;
        uint64 _stakerIndex;
        uint64 _elapsedTick;
        bool _providerFound;
        bool _stakerFound;
    };
    PUBLIC_PROCEDURE_WITH_LOCALS(Stake)
        state._tempLiquid = state._liquids.get(input.liquidId);

        // if liquid was not created, return invocation reward and exit
        if(state._tempLiquid.isCreated) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return;
        }

        state._tempStakingPool = state._stakingPools.get(input.liquidId);

        // if stakingPool was not initialized, return invocation reward and exit
        if(!state._tempStakingPool.isInitialized){
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return;
        }

        for(uint64 i = 0; i < state._tempLiquid.liquidProvidersCount; i++) {
            if(state._tempLiquid.liquidProviders.get(i).owner == qpi.invocator()) {
                locals._providerIndex = i;
                locals._providerFound = true;
                break;
            }
        }

        // if provider was not found, return invocation reward and exit
        if(!locals._providerFound) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return;
        }

        // validate the input lp amount
        if(input.lpAmount > state._tempLiquid.liquidProviders.get(locals._providerIndex).tokenContributions) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return; // Error: Invalid lp amount
        }

        // update staking pool accPerShare
        locals._elapsedTick = qpi.tick() - state._tempStakingPool.lastRewardTick;
        if (state._tempStakingPool.totalStaked > 0) {
            state._tempStakingPool.accPerShare += locals._elapsedTick * 1e12 / state._tempStakingPool.totalStaked;
            state._tempStakingPool.lastRewardTick = qpi.tick();
        } else {
            // if no staked amount, return invocation reward and exit
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return;
        }

        // check if the staker already exists
        for(uint64 i = 0; i < state._tempStakingPool.stakerCount; i++) {
            if(state._tempStakingPool.stakers.get(i).stakerId == qpi.invocator()) {
                locals._stakerIndex = i;
                locals._stakerFound = true;
                break;
            }
        }

        if(!locals._stakerFound) {
            // calculate the reward debt
            locals._rewardDebt = input.lpAmount * state._tempStakingPool.accPerShare;

            // create a new staker
            state._tempStakingPool.stakers.set(state._tempStakingPool.stakerCount, _Staker{ qpi.invocator(), input.lpAmount, locals._rewardDebt });
            state._tempStakingPool.stakerCount++;

            // update the provider
            state._tempLiquid.liquidProviders.set(locals._providerIndex, _LiquidInfo::LiquidProvider{ state._tempLiquid.liquidProviders.get(locals._providerIndex).owner, state._tempLiquid.liquidProviders.get(locals._providerIndex).tokenContributions - input.lpAmount });
        }
        else {
            // calculate the reward
            locals._reward = (input.lpAmount * state._tempStakingPool.accPerShare - state._tempStakingPool.stakers.get(locals._stakerIndex).rewardDebt) / 1e12;

            // transfer the reward to the staker
            // validate totalBonus token amount
            if(state._tempStakingPool.totalBonusTokenAmount < locals._reward) {
                locals._reward = state._tempStakingPool.totalBonusTokenAmount;
            }
            TransferMicroToken_input _transferMicroToken_input{ state._tempStakingPool.bonusTokenInfo.issuer, state._tempStakingPool.bonusTokenInfo.assetName, qpi.invocator(), locals._reward};
            TransferMicroToken_output _transferMicroToken_output;
            CALL(TransferMicroToken, _transferMicroToken_input, _transferMicroToken_output);

            // calculate the reward debt
            locals._rewardDebt = (state._tempStakingPool.stakers.get(locals._stakerIndex).stakedAmount + input.lpAmount) * state._tempStakingPool.accPerShare;
            
            // update the staker
            state._tempStakingPool.stakers.set(locals._stakerIndex, _Staker{ qpi.invocator(), state._tempStakingPool.stakers.get(locals._stakerIndex).stakedAmount + input.lpAmount, locals._rewardDebt });

            // update the provider
            state._tempLiquid.liquidProviders.set(locals._providerIndex, _LiquidInfo::LiquidProvider{ qpi.invocator(), state._tempLiquid.liquidProviders.get(locals._providerIndex).tokenContributions - input.lpAmount });
        }

        // update the liquid and staking pool
        state._liquids.set(input.liquidId, state._tempLiquid);
        state._stakingPools.set(input.liquidId, state._tempStakingPool);
    _
    struct Unstake_locals {
        uint64 _rewardDebt;
        uint64 _reward;
        uint64 _stakerIndex;
        uint64 _providerIndex;
        uint64 _elapsedTick;
        bool _stakerFound;
        bool _providerFound;
    };
    PUBLIC_PROCEDURE_WITH_LOCALS(Unstake)
        state._tempLiquid = state._liquids.get(input.liquidId);

        // if liquid was not created, return invocation reward and exit
        if(state._tempLiquid.isCreated) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return;
        }

        // find the provider
        for(uint64 i = 0; i < state._tempLiquid.liquidProvidersCount; i++) {
            if(state._tempLiquid.liquidProviders.get(i).owner == qpi.invocator()) {
                locals._providerIndex = i;
                locals._providerFound = true;
                break;
            }
        }

        // if provider was not found, return invocation reward and exit
        if(!locals._providerFound) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return;
        }

        state._tempStakingPool = state._stakingPools.get(input.liquidId);

        // if stakingPool was not initialized, return invocation reward and exit
        if(!state._tempStakingPool.isInitialized){
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return;
        }

        // check if the staker exists
        for(uint64 i = 0; i < state._tempStakingPool.stakerCount; i++) {
            if(state._tempStakingPool.stakers.get(i).stakerId == qpi.invocator()) {
                locals._stakerIndex = i;
                locals._stakerFound = true;
                break;
            }
        }

        // if staker was not found, return invocation reward and exit
        if(!locals._stakerFound) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return;
        }

        // validate the unstake amount
        if(input.lpAmount > state._tempStakingPool.stakers.get(locals._stakerIndex).stakedAmount) {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return; // Error: Invalid unstake amount
        }

        // update staking pool accPerShare
        locals._elapsedTick = qpi.tick() - state._tempStakingPool.lastRewardTick;
        if (state._tempStakingPool.totalStaked > 0) {
            state._tempStakingPool.accPerShare += locals._elapsedTick * 1e12 / state._tempStakingPool.totalStaked;
            state._tempStakingPool.lastRewardTick = qpi.tick();
        } else {
            // if no staked amount, return invocation reward and exit
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
            return;
        }

        // calculate the reward
        locals._reward = (state._tempStakingPool.stakers.get(locals._stakerIndex).stakedAmount * state._tempStakingPool.accPerShare - state._tempStakingPool.stakers.get(locals._stakerIndex).rewardDebt) / 1e12;

        // transfer the reward to the staker
        // validate totalBonus token amount
        if(state._tempStakingPool.totalBonusTokenAmount < locals._reward) {
            locals._reward = state._tempStakingPool.totalBonusTokenAmount;
        }
        TransferMicroToken_input _transferMicroToken_input{ state._tempStakingPool.bonusTokenInfo.issuer, state._tempStakingPool.bonusTokenInfo.assetName, qpi.invocator(), locals._reward};
        TransferMicroToken_output _transferMicroToken_output;
        CALL(TransferMicroToken, _transferMicroToken_input, _transferMicroToken_output);

        // update the staker's staked amount and reward debt
        locals._rewardDebt = (state._tempStakingPool.stakers.get(locals._stakerIndex).stakedAmount - input.lpAmount) * state._tempStakingPool.accPerShare;
        state._tempStakingPool.stakers.set(locals._stakerIndex, _Staker{ qpi.invocator(), state._tempStakingPool.stakers.get(locals._stakerIndex).stakedAmount - input.lpAmount, locals._rewardDebt });

        // update the provider's contributions
        state._tempLiquid.liquidProviders.set(locals._providerIndex, _LiquidInfo::LiquidProvider{ qpi.invocator(), state._tempLiquid.liquidProviders.get(locals._providerIndex).tokenContributions + input.lpAmount });

        // update the liquid and staking pool
        state._liquids.set(input.liquidId, state._tempLiquid);
        state._stakingPools.set(input.liquidId, state._tempStakingPool);
    _
    REGISTER_USER_FUNCTIONS_AND_PROCEDURES
        REGISTER_USER_FUNCTION(MicroTokenAllowance, 1);
        REGISTER_USER_FUNCTION(BalanceOfMicroToken, 2);
        REGISTER_USER_FUNCTION(ExamPublic, 3);

        REGISTER_USER_PROCEDURE(ApproveMicroToken, 1);
        REGISTER_USER_PROCEDURE(TransferMicroToken, 2);
        REGISTER_USER_PROCEDURE(TransferFromMicroToken, 3);
        REGISTER_USER_PROCEDURE(ConvertToMicroToken, 4);
        REGISTER_USER_PROCEDURE(ConvertToExpensiveToken, 5);
        REGISTER_USER_PROCEDURE(CreateLiquid, 6);
        REGISTER_USER_PROCEDURE(AddLiquid, 7);
        REGISTER_USER_PROCEDURE(RemoveLiquid, 8);
        REGISTER_USER_PROCEDURE(SwapToQU, 9);
        REGISTER_USER_PROCEDURE(SwapFromQU, 10);
        REGISTER_USER_PROCEDURE(SwapToQwallet, 11);
        REGISTER_USER_PROCEDURE(SwapFromQwallet, 12);
        REGISTER_USER_PROCEDURE(SwapQUToQwallet, 13);
        REGISTER_USER_PROCEDURE(SwapQwalletToQU, 14);
        REGISTER_USER_PROCEDURE(SingleSwap, 15);
        REGISTER_USER_PROCEDURE(CrossSwap, 16);
    _

    INITIALIZE
    _

	BEGIN_EPOCH
	_

	END_EPOCH
	_

	BEGIN_TICK
	_

	END_TICK
	_

	EXPAND
	_
};
