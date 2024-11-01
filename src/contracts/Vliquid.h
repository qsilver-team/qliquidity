using namespace QPI;
#define VLIQUID_CONTRACTID _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 9)

#define MILLION 1000000

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
    
    REGISTER_USER_FUNCTIONS_AND_PROCEDURES
        REGISTER_USER_FUNCTION(MicroTokenAllowance, 1);
        REGISTER_USER_FUNCTION(BalanceOfMicroToken, 2);
        REGISTER_USER_FUNCTION(ExamPublic, 3);

        REGISTER_USER_PROCEDURE(ApproveMicroToken, 1);
        REGISTER_USER_PROCEDURE(TransferMicroToken, 2);
        REGISTER_USER_PROCEDURE(TransferFromMicroToken, 3);
        REGISTER_USER_PROCEDURE(ConvertToMicroToken, 4);
        REGISTER_USER_PROCEDURE(ConvertToExpensiveToken, 5);
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
