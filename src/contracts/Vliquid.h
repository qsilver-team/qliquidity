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

    struct SingleSwap_input
    {
        uint64 liquidId;
        uint64 inputTokenAssetName;
        uint64 outputTokenAssetName;
        uint64 inputAmount;
    };

    struct SingleSwap_output
    {
        uint64 outputAmount;
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
		id creator;
		bool isCreated;
	};

    _LiquidInfo _newLiquid;

	array<_LiquidInfo, LIQUIDS_LENGTH> _liquids;
	uint64 _liquidsCount;

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

        state._newLiquid.liquidProviders.set(0, locals._newProvider);

		// Execute transfer each token
		for(uint8 i = 0; i < input.tokenLength; i ++) {
			// const CreateLiquid_input::TokenInfo& _nthToken = input.tokens.get(i);

			if(input.tokens.get(i).tokenInfo.isMicroToken)
			{
				// Execute the MicroToken transfer
				TransferFromMicroToken_input _transferFromMicroToken_input{ input.tokens.get(i).tokenInfo.issuer, input.tokens.get(i).tokenInfo.assetName, qpi.invocator(), VLIQUID_CONTRACTID, input.tokens.get(i).balance};
				TransferFromMicroToken_output _transferFromMicroToken_output;

				CALL(TransferFromMicroToken, _transferFromMicroToken_input, _transferFromMicroToken_output);
                state._newLiquid.tokens.set(i, input.tokens.get(i));
			}
			else
			{
				// Transfer ownership and possession of shares to this contract
				qpi.transferShareOwnershipAndPossession(input.tokens.get(i).tokenInfo.assetName, input.tokens.get(i).tokenInfo.issuer, qpi.invocator(), qpi.invocator(), input.tokens.get(i).balance, VLIQUID_CONTRACTID);
                // Convert ExpensiveToken to MicroToken
                ConvertToMicroToken_input _convertToMicroToken_input{ input.tokens.get(i).tokenInfo.issuer, input.tokens.get(i).tokenInfo.assetName, static_cast<sint64>(input.tokens.get(i).balance) };
                ConvertToMicroToken_output _convertToMicroToken_output;
                CALL(ConvertToMicroToken, _convertToMicroToken_input, _convertToMicroToken_output);
                state._newLiquid.tokens.set(i, Token{ TokenInfo{input.tokens.get(i).tokenInfo.issuer, input.tokens.get(i).tokenInfo.assetName, true}, _convertToMicroToken_output.microTokenAmount, input.tokens.get(i).weight});
			}
		}

        state._newLiquid.tokenLength = input.tokenLength;
        state._newLiquid.quBalance = input.quShares;
        state._newLiquid.quWeight = input.quWeight;
        state._newLiquid.totalWeight = locals._totalWeight;
        state._newLiquid.totalLiquid = input.initialLiquid;
        state._newLiquid.feeRate = input.feeRate;
        state._newLiquid.liquidProvidersCount = 1;
        state._newLiquid.creator = qpi.invocator();
        state._newLiquid.isCreated = true;

		// Store the newly created liquid pool and assign an ID
		state._liquids.set(state._liquidsCount, state._newLiquid);
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
		state._newLiquid = state._liquids.get(input.liquidId);
		
		// Ensure the liquid has been created
		if(!state._newLiquid.isCreated) {
			qpi.transfer(qpi.invocator(), qpi.invocationReward());
			return; // Error: the liquid is not created
		}

		// Calculate the required QU contribution based on the input token contribution
		locals._quContribution = state._newLiquid.quBalance * input.tokenContribution / state._newLiquid.totalLiquid;

		// Handle the invocation reward with respect to the QU contribution
        if (qpi.invocationReward() < static_cast<sint64>(locals._quContribution)) {
			// Transfer invocation reward if it's less than required quContribution
			qpi.transfer(qpi.invocator(), qpi.invocationReward());
			return;
        }
        else if (qpi.invocationReward() > static_cast<sint64>(locals._quContribution)) {
			// Transfer excess invocation reward if it exceeds the required QU contribution
			qpi.transfer(qpi.invocator(), qpi.invocationReward() - locals._quContribution);

			state._newLiquid.quBalance += locals._quContribution;
		}

		// Find or create a liquid provider entry for the invocator
        locals._providerFound = false;
        for (uint64 i = 0; i < state._newLiquid.liquidProvidersCount; i++) {
            if (state._newLiquid.liquidProviders.get(i).owner == qpi.invocator()) {
                locals._provider = state._newLiquid.liquidProviders.get(i);
                locals._providerFound = true;
            }
        }

        if (!locals._providerFound) {
            locals._provider = _LiquidInfo::LiquidProvider{ qpi.invocator(), 0 };
            state._newLiquid.liquidProviders.set(state._newLiquid.liquidProvidersCount, locals._provider);
            state._newLiquid.liquidProvidersCount++;
        }

		// Validate each token in the liquidity pool
		for(uint8 i = 0; i < state._newLiquid.tokenLength; i ++) {
			uint64 _nthTokenContribution = state._newLiquid.tokens.get(i).balance * input.tokenContribution / state._newLiquid.totalLiquid;
			
			// Handle token-specific validations and transfers
			if(state._newLiquid.tokens.get(i).tokenInfo.isMicroToken)
			{
				// Validate and transfer MicroTokens
				MicroTokenAllowance_input _microTokenAllowance_input{ state._newLiquid.tokens.get(i).tokenInfo.issuer, state._newLiquid.tokens.get(i).tokenInfo.assetName, VLIQUID_CONTRACTID, qpi.invocator()};
				MicroTokenAllowance_output _microTokenAllowance_output;
				CALL(MicroTokenAllowance, _microTokenAllowance_input, _microTokenAllowance_output);
				if (_microTokenAllowance_output.balance < _nthTokenContribution)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
					return; // Error: insufficient MicroToken allowance
				}
				
				// Ensure MicroToken balance is sufficient compared to initial balance
				BalanceOfMicroToken_input _balanceOfMicroToken_input{ state._newLiquid.tokens.get(i).tokenInfo.issuer, state._newLiquid.tokens.get(i).tokenInfo.assetName, qpi.invocator()};
				BalanceOfMicroToken_output _balanceOfMicroToken_output;
                CALL(BalanceOfMicroToken, _balanceOfMicroToken_input, _balanceOfMicroToken_output);
				if(_balanceOfMicroToken_output.balance < _nthTokenContribution){
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
					return; // Error: insufficient MicroToken balance
				}
			
				// Update the token balance in the liquid
                state._newLiquid.tokens.set(i, Token{state._newLiquid.tokens.get(i).tokenInfo, state._newLiquid.tokens.get(i).balance + _nthTokenContribution, state._newLiquid.tokens.get(i).weight});
			}
			else
			{
				// Ensure sufficient token shares for non-MicroTokens
                if (qpi.numberOfPossessedShares(state._newLiquid.tokens.get(i).tokenInfo.assetName, state._newLiquid.tokens.get(i).tokenInfo.issuer, qpi.invocator(), qpi.invocator(), SELF_INDEX, SELF_INDEX) < static_cast<sint64>(_nthTokenContribution)) {
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
					return; // Error: insufficient token shares
				}

				// Update the token balance in the liquid
                state._newLiquid.tokens.set(i, Token{ state._newLiquid.tokens.get(i).tokenInfo, state._newLiquid.tokens.get(i).balance + _nthTokenContribution * MILLION, state._newLiquid.tokens.get(i).weight });
			}
            // locals._liquid.tokens.set(i, locals._nthToken);
		}

		// Execute transfer each token
		for(uint8 i = 0; i < state._newLiquid.tokenLength; i ++) {
			// const _LiquidInfo::TokenInfo& _nthToken = locals._liquid.tokens.get(i);
			uint64 _nthTokenContribution = state._newLiquid.tokens.get(i).balance * input.tokenContribution / state._newLiquid.totalLiquid;
			
			// Handle token-specific validations and transfers
			if(state._newLiquid.tokens.get(i).tokenInfo.isMicroToken)
			{
				// Execute the MicroToken transfer
				TransferFromMicroToken_input _transferFromMicroToken_input{ state._newLiquid.tokens.get(i).tokenInfo.issuer, state._newLiquid.tokens.get(i).tokenInfo.assetName, qpi.invocator(), VLIQUID_CONTRACTID, _nthTokenContribution};
				TransferFromMicroToken_output _transferFromMicroToken_output;

				CALL(TransferFromMicroToken, _transferFromMicroToken_input, _transferFromMicroToken_output);
			}
			else
			{
				// Transfer ownership and possession of shares to this contract
				qpi.transferShareOwnershipAndPossession(state._newLiquid.tokens.get(i).tokenInfo.assetName, state._newLiquid.tokens.get(i).tokenInfo.issuer, qpi.invocator(), qpi.invocator(), _nthTokenContribution / MILLION, VLIQUID_CONTRACTID);
			}
		}

		// Update the liquid provider's contributions and the total liquidity of the liquid
		locals._provider.tokenContributions += input.tokenContribution;
		state._newLiquid.totalLiquid += input.tokenContribution;
		state._liquids.set(input.liquidId, state._newLiquid);
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
		state._newLiquid = state._liquids.get(input.liquidId);
		
		// Find the provider associated with the invocator
		// locals._provider = _findProvder(locals._liquid, qpi.invocator());
        locals._providerFound = false;
        for (uint64 i = 0; i < state._newLiquid.liquidProvidersCount; i++) {
            locals._provider = state._newLiquid.liquidProviders.get(i);
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
		uint64 _removedQuBalance = state._newLiquid.quBalance * input.tokenContribution / state._newLiquid.totalLiquid;
		qpi.transfer(qpi.invocator(), _removedQuBalance);
        state._newLiquid.quBalance -= _removedQuBalance;

		// Process each token in the liquid pool
		// Token transfer
		for(uint8 i = 0; i < state._newLiquid.tokenLength; i ++) {
			// Calculate the micro token amount of tokens to remove
			locals._removedBalance = state._newLiquid.tokens.get(i).balance * input.tokenContribution / state._newLiquid.totalLiquid;

			TransferMicroToken_input _transferMicroToken_input{ state._newLiquid.tokens.get(i).tokenInfo.issuer, state._newLiquid.tokens.get(i).tokenInfo.assetName, VLIQUID_CONTRACTID, locals._removedBalance};
			TransferMicroToken_output _transferMicroToken_output;
			CALL(TransferMicroToken, _transferMicroToken_input, _transferMicroToken_output);

			// Update the micro token balance in the liquid pool

            state._newLiquid.tokens.set(i, Token{ state._newLiquid.tokens.get(i).tokenInfo, state._newLiquid.tokens.get(i).balance - locals._removedBalance, state._newLiquid.tokens.get(i).weight });
		}

		// Update the provider's contribution and the total liquid in the pool
		locals._provider.tokenContributions -= input.tokenContribution;
		state._newLiquid.totalLiquid -= input.tokenContribution;

		// If the provider has withdrawn all contributions, remove them from the poroviders list
		if (locals._provider.tokenContributions == 0) {
			// _removeProvider(locals._liquid, qpi.invocator());
            for (uint64 i = 0; i < state._newLiquid.liquidProvidersCount; i++) {
                locals._provider = state._newLiquid.liquidProviders.get(i);

                if (locals._provider.owner == qpi.invocator()) {
                    if (i == state._newLiquid.liquidProvidersCount - 1) {
                        state._newLiquid.liquidProvidersCount--;
                    }
                    else {
                        locals._lastProvider = state._newLiquid.liquidProviders.get(state._newLiquid.liquidProvidersCount - 1);
                        state._newLiquid.liquidProviders.set(i, locals._lastProvider);
                        state._newLiquid.liquidProvidersCount--;
                    }
                }
            }
		}

		// Save the updated liquid state
		state._liquids.set(input.liquidId, state._newLiquid);

		output.removedContribution = input.tokenContribution;
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
