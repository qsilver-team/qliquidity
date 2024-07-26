using namespace QPI;

#define MILLION 1000000
#define VLIQUID_CONTRACTID _mm256_set_epi32(0, 0, 0, 0, 0, 0, 0, 7)

struct VLIQUID2
{
    
};

struct VLIQUID
{
public:
    // declare structs
	struct BigNumToStr_input {
		sint64 a;
	};
	struct BigNumToStr_output {
		uint8 len;
		uint8_128 result;
	};

	struct BigStrToNum_input {
		uint8 len;
		uint8_128 a;
	};
	struct BigStrToNum_output {
		sint64 result;
	};

	struct BigPlus_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};
	struct BigPlus_output {
		uint8 resultlen;
		uint8_128 result;
	};

	struct BigMinus_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};
	struct BigMinus_output {
		uint8 resultlen;
		uint8_128 result;
	};

	struct BigMultiply_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};
	struct BigMultiply_output {
		uint8 resultlen;
		uint8_128 result;
	};

	struct BigDiv_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};
	struct BigDiv_output {
		uint8 resultlen;
		uint8_128 result;
	};

	struct BigModulus_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};
	struct BigModulus_output {
		uint8 resultlen;
		uint8_128 result;
	};

	struct BigGreaterOrEqual_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};
	struct BigGreaterOrEqual_output {
		bit result;
	};

	struct BigLessOrEqual_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};
	struct BigLessOrEqual_output {
		bit result;
	};

	struct BigGreater_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};
	struct BigGreater_output {
		bit result;
	};

	struct BigLess_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};
	struct BigLess_output {
		bit result;
	};

    struct ConvertToMicroToken_input
    {
        id issuer;
        uint64 assetName;
        sint64 expensiveTokenAmount;
    }
    struct ConvertToMicroToken_output
    {
        uint64 microTokenAmount;
    }

    struct ConvertToExpensiveToken_input
    {
        id issuer;
        uint64 assetName;
        uint64 microTokenAmount;
    }
    struct ConvertToExpensiveToken_output
    {
        sint64 expensiveTokenAmount;
    }

    struct TransferMicroToken_input
    {
        id issuer;
        id recipient;
        uint64 assetName;
        uint64 microTokenAmount;
    }
    struct TransferMicroToken_output
    {
        uint64 transferredMicroTokenAmount;
    }

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
	}
	struct BalanceOfMicroToken_output
	{
		uint64 balance;
	}

    struct ApproveMicroToken_input
    {
        id issuer;
        id recipient;
        uint64 assetName;
        uint64 microTokenAmount;
    }
    struct ApproveMicroToken_output
    {
        uint64 approvedMicroTokenAmount;
    }

    struct TransferFromMicroToken_input
    {
        id issuer;
        uint64 assetName;
        id spender;
        id recipient;
        uint64 microTokenAmount;
    }
    struct TransferFromMicroToken_output
    {
        uint64 transferredMicroTokenAmount;
    }

    struct CreateLiquid_input
    {
        
    }
    struct CreateLiquid_output
    {

    }

    struct AddLiquidity_input
    {
        
    }
    struct AddLiquidity_output
    {

    }

    struct RemoveLiquidity_input
    {
        
    }
    struct RemoveLiquidity_output
    {

    }

    struct Swap_input
    {
        
    }
    struct Swap_output
    {

    }

private:
    // declare state variables
    struct _MicroTokenBalance {
        id owner;
        id issuer;
        uint64 assetName;
        uint64 balance;
    }
    
    array<_MicroTokenBalance, 16777216> _microTokenBalances;

    struct _MicroTokenAllowance {
        id recipient;
        id spender;
        id issuer;
        uint64 assetName;
        uint64 balance;
    }

    array<_MicroTokenAllowance, 16777216> _microTokenAllowances;

    struct _LiquidInfo
    {
    }

    // declare structs
	struct _BigNumToStr_input {
		sint64 a;
	};
	struct _BigNumToStr_output {
		uint8 len;
		uint8_128 result;
	};

	struct _BalanceOfMicroToken_input {
		id issuer;
		uint64 assetName;
		id owner;
	};
	struct _BalanceOfMicroToken_output {
		uint64 balance;
	}

	struct _BigStrToNum_input {
		uint8 len;
		uint8_128 a;
	};
	struct _BigStrToNum_output {
		sint64 result;
	};

	struct _BigPlus_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};
	struct _BigPlus_output {
		uint8 resultlen;
		uint8_128 result;
	};

	struct _BigMinus_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};
	struct _BigMinus_output {
		uint8 resultlen;
		uint8_128 result;
	};

	struct _BigMultiply_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};
	struct _BigMultiply_output {
		uint8 resultlen;
		uint8_128 result;
	};

	struct _BigDiv_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};
	struct _BigDiv_output {
		uint8 resultlen;
		uint8_128 result;
	};

	struct _BigModulus_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};
	struct _BigModulus_output {
		uint8 resultlen;
		uint8_128 result;
	};

	struct _BigGreaterOrEqual_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};
	struct _BigGreaterOrEqual_output {
		bit result;
	};

	struct _BigLessOrEqual_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};
	struct _BigLessOrEqual_output {
		bit result;
	};

	struct _BigGreater_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};
	struct _BigGreater_output {
		bit result;
	};

	struct _BigLess_input {
		uint8 alen;
		uint8 blen;
		uint8_128 a;
		uint8_128 b;
	};
	struct _BigLess_output {
		bit result;
	};

    struct _MintMicroToken_input
    {
        id issuer;
        uint64 assetName;
        uint64 microTokenAmount;
    }
    struct _MintMicroToken_output
    {
        uint64 mintedMicroTokenAmount;
    }

    struct _BurnMicroToken_input
    {
        id issuer;
        uint64 assetName;
        uint64 microTokenAmount;
    }
    struct _BurnMicroToken_output
    {
        uint64 burntMicroTokenAmount;
    }

    struct _LockExpensiveToken_input
    {
        id issuer;
        uint64 assetName;
        sint64 expensiveTokenAmount;
    }
    struct _LockExpensiveToken_output
    {
        sint64 lockedExpensiveTokenAmount;
    }

    struct _UnLockExpensiveToken_input
    {
        id issuer;
        uint64 assetName;
        sint64 expensiveTokenAmount;
    }
    struct _UnLockExpensiveToken_output
    {
        sint64 unLockedExpensiveTokenAmount;
    }
    
    _

    // write PRIVATE_FUNCTION

    PRIVATE_FUNCTION(_BigStrToNum)
		if(input.len == 0) {
			return;
		}
		//when negative
		if(input.a.get(0) == 45) { // if first element is '-'
			if(input.len > 20 || input.len < 2) {
				return;
			}
			// checking if a is number
			for(uint8 i = 1 ; i < input.len; i++) {
				if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;
				return;
			}
		}
		else { // when positive
			if(input.len > 19 || input.len < 1) {
				return;
			}
			// checking if a is number
			for(uint8 i = 0; i < input.len; i++) {
				if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;
				return;
			}
		}
		
		if(input.a.get(0) == 45) output.result = (input.a.get(1) - '0') * (-1);
		else output.result = input.a.get(0) - '0';

		for(uint8 i = 1 ; i < (input.a.get(0) == 45?input.len - 1:input.len); i++) {
			if(input.a.get(0) == 45) output.result = output.result * 10 - (input.a.get(i + 1) - '0');
			else output.result = output.result * 10 + (input.a.get(i) - '0');
		}
    _
	
	PRIVATE_FUNCTION(_BalanceOfMicroToken)
		output.balance = 0
		for (const auto& item : _microTokenBalances)
		{
			if (item.issuer == input.issuer &&
				item.assetName = input.assetName &&
				item.owner = input.owner)
			{
				output.balance = item.balance;
				break;
			}
		}
	_
    // write PRIVATE_FUNCTION_WITH_LOCALS

    struct _BigNumToStr_locals
    {
        sint64 _a; // input number
        uint64 _p; // power of ten
    }
    PRIVATE_FUNCTION_WITH_LOCALS(_BigNumToStr)
        locals._a = input.a;
        locals._p = 1;
        output.len = 1;

        if(locals._a < 0) {
            output.result.set(0, '-');
            output.len = 2;
            locals._a *= -1;
        }
        while(locals._a / 10) {
            output.len++;
            locals._a /= 10;
            locals._p *= 10;
        }

        locals._a = input.a;
        if(locals._a < 0) locals._a *= -1;
        
        for(uint8 i = 0; i < (input.a < 0 ? output.len - 1 : output.len); i++) {
            if(input.a < 0) 
                output.result.set(i + 1, (locals._a / locals._p) + '0');
            else 
                output.result.set(i, (locals._a / locals._p) + '0');
            locals._a %= locals._p;
            locals._p /= 10;
        }
    }
    _

	// Plus operator
	// BIGPlus is only available for positive input. if there is negative input, the output would be wrong result.

    struct _BigPlus_locals
    {
        uint8 _maxlen;
        uint8_128 _tempa;
        uint8_128 _tempb;
        uint8_128 _tempResult;
    }
    PRIVATE_FUNCTION_WITH_LOCALS(_BigPlus)
		// checking if a is positive
		for(uint8 i = 0; i < input.alen; i++) {
			if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;
			return;
		}
		// checking if b is positive
		for(uint8 i = 0; i < input.blen; i++) {
			if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;
			return;
		}

		locals._maxlen = input.alen > input.blen ? input.alen: input.blen;

		for(uint8 i = 0 ; i < input.alen; i++) locals._tempa.set(i, input.a.get(input.alen - i - 1));     // reverse
		for(uint8 i = 0 ; i < input.blen; i++) locals._tempb.set(i, input.b.get(input.blen - i - 1));     // reverse
	
		bit carry = 0;

		output.resultlen = locals._maxlen;

		for(uint8 i = 0; i < locals._maxlen || carry; i++) {
			uint8 sum = carry;
			if(i < input.alen) sum += locals._tempa.get(i) - '0';
			if(i < input.blen) sum += locals._tempb.get(i) - '0';

			carry = sum >= 10;
			if(carry) sum -= 10;
			if(i == locals._maxlen) output.resultlen++;

			locals._tempResult.set(i, sum + '0');
		}

		for(uint8 i = 0 ; i < locals._resultlen; i++) locals._result.set(i, locals._tempResult.get(locals._resultlen - i - 1));     // reverse

		_BigStrToNum_input _bigStrToNum_input;
		_BigStrToNum_output _bigStrToNum_output;
		_bigStrToNum_input.len = locals._resultlen;
		_bigStrToNum_input.a = locals._result;
		CALL(_BigStrToNum, _bigStrToNum_input, _bigStrToNum_output);

		output.result = _bigStrToNum_output.result;
    _

	// Minus operator   
	// BIGMinus is only available for positive result. if there is negative result, the output would be wrong result.

    struct _BigMinus_locals
    {
		uint8_128 _tempa;
		uint8_128 _tempb;
		uint8_128 _tempResult;
		bit _borrow;
		uint8 _zeroCount;
    }
    PRIVATE_FUNCTION_WITH_LOCALS(_BigMinus)
		// checking if the result would be positive
		if (input.blen > input.alen) {
			return;
		}

		// checking if a is positive
		for(uint8 i = 0; i < input.alen; i++) {
			if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;
			return;
		}
		// checking if b is positive
		for(uint8 i = 0; i < input.blen; i++) {
			if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;
			return;
		}

		for(uint8 i = 0 ; i < input.alen; i++) locals._tempa.set(i, input.a.get(input.alen - i - 1));     // reverse
		for(uint8 i = 0 ; i < input.blen; i++) locals._tempb.set(i, input.b.get(input.blen - i - 1));     // reverse

		locals._borrow = 0;
		for (uint8 i = 0; i < input.alen; i++) {
			sint8 diff = (locals._tempa.get(i) - '0') - locals._borrow;
			if(i < input.blen) diff -= locals._tempb.get(i) - '0';
			if(i == input.alen - 1 && input.alen == input.blen && diff < 0) {   // checking if the result would be positive
				return;
			}
			locals._borrow =  diff < 0 ? 1 : 0;
			if(diff < 0) diff += 10;
			
			locals._tempResult.set(i, diff + '0');
		}

		for(uint8 i = 0 ; i < input.alen; i++) output.result.set(i, locals._tempResult.get(input.alen - i - 1));     // reverse

		locals._zeroCount = 0;

		for(uint8 i = 0 ; i < input.alen; i++) {
			if(output.result.get(i) != '0') break;
			locals._zeroCount++;
		}

		output.resultlen = 0;
		for(uint8 i = locals._zeroCount; i < input.alen; i++) output.result.set(output.resultlen++, output.result.get(i));
		output.result.set(output.resultlen, '0');
    _

    struct _BigMultiply_locals
    {
		uint8_128 _tempa;
		uint8_128 _tempb;
		uint8_128 _tempResult;
		uint8 _length;
		bit _zeroCheck;
    }
    PRIVATE_FUNCTION_WITH_LOCALS(_BigMultiply)
		if(input.a.get(0) == '-') {     // when a is negative
			// checking if a is number
			for(uint8 i = 1 ; i < input.alen; i++) {
				locals._tempa.set(i - 1, input.a.get(input.alen - i));
				if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;
				return;
			}
		}
		else {                // when positive
			// checking if a is number
			for(uint8 i = 0; i < input.alen; i++) {
				locals._tempa.set(i, input.a.get(input.alen - i - 1));
				if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;
				return;
			}
		}

		if(input.b.get(0) == '-') {     // when b is negative
			// checking if b is number
			for(uint8 i = 1 ; i < input.blen; i++) {
				locals._tempb.set(i - 1, input.b.get(input.blen - i));
				if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;
				return;
			}
		}
		else {                // when positive
			// checking if b is number
			for(uint8 i = 0; i < input.blen; i++) {
				locals._tempb.set(i, input.b.get(input.blen - i - 1));
				if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;
				return;
			}
		}

		for(uint8 i = 0 ; i < input.alen + input.blen; i++) locals._tempResult.set(i, '0');
		for (uint8 i = 0; i < (input.a.get(0) == '-'? input.alen - 1: input.alen); i++) {
			uint8 carry = 0;
			for (uint8 j = 0; j < (input.b.get(0) == '-'? input.blen - 1: input.blen) || carry; j++) {
				uint8 current;
				if(input.b.get(0) == '-') {
					current = (locals._tempResult.get(i + j) - '0') + (locals._tempa.get(i) - '0') * (j < input.blen - 1 ? (locals._tempb.get(j) - '0') : 0) + carry;
					if(input.a.get(0) == '-' && i == input.alen - 2 && j == input.blen - 2 && current >= 10) output.resultlen++;
					if(input.a.get(0) != '-' && i == input.alen - 1 && j == input.blen - 2 && current >= 10) output.resultlen++;
				}
				else {
					current = (locals._tempResult.get(i + j) - '0') + (locals._tempa.get(i) - '0') * (j < input.blen ? (locals._tempb.get(j) - '0') : 0) + carry;
					if(input.a.get(0) == '-' && i == input.alen - 2 && j == input.blen - 1 && current >= 10) output.resultlen++;
					if(input.a.get(0) != '-' && i == input.alen - 1 && j == input.blen - 1 && current >= 10) output.resultlen++;
				}

				carry = current / 10;
				locals._tempResult.set(i + j, (current % 10) + '0');
			}
		}

		locals._length = 0;
		if((input.a.get(0) == 45 && input.b.get(0) != 45) || (input.a.get(0) != 45 && input.b.get(0) == 45)) {
			locals._length = 1;
			output.result.set(0, 45);
		}
		locals._zeroCheck = 0;
		for(uint8 i = 0; i < input.alen + input.blen; i++) {
			if(locals._tempResult.get(input.alen + input.blen - i - 1) != '0' || locals._zeroCheck) {
				locals._zeroCheck = 1;
				output.result.set(locals._length++, locals._tempResult.get(input.alen + input.blen - i - 1));     // reverse
			}
		}
		output.resultlen = locals._length;
    _

    struct _BigDiv_locals
    {
        uint8_128 _tempa;
		uint8_128 _tempb;
		uint8 _tempalen;
		uint8 _tempblen;
		uint8_128 _tempResult;
		bit _sign;
		uint8_128 _current;
		uint8 _currentLen;
		bit _flag;
    }
    PRIVATE_FUNCTION_WITH_LOCALS(_BigDiv)
		locals._tempalen = 0;
		locals._tempblen = 0;
		locals._sign = 0;
		if(input.a.get(0) == '-') {     // when a is negative
			locals._sign ^= 1;
			bit flag = 0;
			// checking if a is number
			for(uint8 i = 1 ; i < input.alen; i++) {
				if(input.a.get(i) != '0' || flag) {
					flag = 1;
					locals._tempa.set(locals._tempalen++, input.a.get(i));
				}
				if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;
				return;
			}
		}
		else { // when positive
			// checking if a is number
			bit flag = 0;
			for(uint8 i = 0; i < input.alen; i++) {
				if(input.a.get(i) != '0' || flag) {
					flag = 1;
					locals._tempa.set(locals._tempalen++, input.a.get(i));
				}
				if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;
				return;
			}
		}

		if(input.b.get(0) == '-') { // when b is negative
			locals._sign ^= 1;
			uint8 zeroCount = 0;
			bit flag = 0;
			// checking if b is number
			for(uint8 i = 1 ; i < input.blen; i++) {
				if(input.b.get(i) != '0' || flag) {
					flag = 1;
					locals._tempb.set(locals._tempblen++, input.b.get(i));
				}
				if(input.b.get(i) == '0') zeroCount++;
				if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;
				return;
			}

			if(zeroCount == input.blen - 1) { //  div by zoro
				return;
			}
		}
		else { // when positive
			uint8 zeroCount = 0;
			bit flag = 0;
			// checking if b is number
			for(uint8 i = 0; i < input.blen; i++) {
				if(input.b.get(i) != '0' || flag) {
					flag = 1;
					locals._tempb.set(locals._tempblen++, input.b.get(i));
				}
				if(input.b.get(i) == '0') zeroCount++;
				if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;

				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}

			if(zeroCount == input.blen) {             //  div by zoro
				if (qpi.invocationReward() > 0)
				{
					qpi.transfer(qpi.invocator(), qpi.invocationReward());
				}
				return;
			}
		}

		locals._current;
		locals._currentLen = 0;
		for (uint8 i = 0; i < locals._tempalen; i++) {
			locals._current.set(locals._currentLen++, locals._tempa.get(i));
			uint8 count = 0;

			while (1) {
				_BigGreaterOrEqual_input compInput;
				_BigGreaterOrEqual_output compOutput;
				for(uint8 j = 0 ; j < locals._currentLen; j++) compInput.a.set(j, locals._current.get(j));
				compInput.alen = locals._currentLen;
				for(uint8 j = 0 ; j < locals._tempblen; j++) compInput.b.set(j, locals._tempb.get(j));
				compInput.blen = locals._tempblen;
				CALL(_BigGreaterOrEqual, compInput, compOutput);

				if(!compOutput.result) break;

				_BigMinus_input minusInput;
				_BigMinus_output minusOutput;
				for(uint8 j = 0 ; j < locals._currentLen; j++) minusInput.a.set(j, locals._current.get(j));
				minusInput.alen = locals._currentLen;
				for(uint8 j = 0 ; j < locals._tempblen; j++) minusInput.b.set(j, locals._tempb.get(j));
				minusInput.blen = locals._tempblen;
				
				CALL(_BigMinus, minusInput, minusOutput);
				for(uint8 j = 0 ; j < minusOutput.resultlen; j++) locals._current.set(j, minusOutput.result.get(j));
				locals._currentLen = minusOutput.resultlen;
				count++;
			}
			locals._tempResult.set(i, count + '0');
		}

		output.resultlen = 0;

		if(locals._sign) {
			output.result.set(0, '-');
			output.resultlen = 1;
		}
		locals._flag = 0;
		for(uint8 i = 0; i < locals._tempalen; i++) {
			if(locals._tempResult.get(i) != '0' || locals._flag) {
				locals._flag = 1;
				output.result.set(output.resultlen++, locals._tempResult.get(i));
			}
		}
    _

    struct _BigModulus_locals
    {
		uint8_128 _tempa;
		uint8_128 _tempb;
		uint8 _tempalen;
		uint8 _tempblen;
		uint8_128 _tempResult;
		bit _sign;
		uint8_128 _current;
		uint8 _currentLen;
		bit _flag;
    }
    PRIVATE_FUNCTION_WITH_LOCALS(_BigModulus)
		locals._tempalen = 0;
		locals._tempblen = 0;
		locals._sign = 0;
		if(input.a.get(0) == '-') {     // when a is negative
			locals._sign ^= 1;
			bit flag = 0;
			// checking if a is number
			for(uint8 i = 1 ; i < input.alen; i++) {
				if(input.a.get(i) != '0' || flag) {
					flag = 1;
					locals._tempa.set(locals._tempalen++, input.a.get(i));
				}
				if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;
				return;
			}
		}
		else {                // when positive
			// checking if a is number
			bit flag = 0;
			for(uint8 i = 0; i < input.alen; i++) {
				if(input.a.get(i) != '0' || flag) {
					flag = 1;
					locals._tempa.set(locals._tempalen++, input.a.get(i));
				}
				if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;
				return;
			}
		}

		if(input.b.get(0) == '-') {     // when b is negative
			locals._sign ^= 1;
			uint8 zeroCount = 0;
			bit flag = 0;
			// checking if b is number
			for(uint8 i = 1 ; i < input.blen; i++) {
				if(input.b.get(i) != '0' || flag) {
					flag = 1;
					locals._tempb.set(locals._tempblen++, input.b.get(i));
				}
				if(input.b.get(i) == '0') zeroCount++;
				if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;
				return;
			}

			if(zeroCount == input.blen - 1) {             //  div by zoro
				return;
			}
		}
		else {                // when positive
			uint8 zeroCount = 0;
			bit flag = 0;
			// checking if b is number
			for(uint8 i = 0; i < input.blen; i++) {
				if(input.b.get(i) != '0' || flag) {
					flag = 1;
					locals._tempb.set(locals._tempblen++, input.b.get(i));
				}
				if(input.b.get(i) == '0') zeroCount++;
				if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;
				return;
			}

			if(zeroCount == input.blen) {             //  div by zoro
				return;
			}
		}

		locals._currentLen = 0;
		for (uint8 i = 0; i < locals._tempalen; i++) {
			locals._current.set(locals._currentLen++, locals._tempa.get(i));
			uint8 count = 0;

			while (1) {
				_BigGreaterOrEqual_input compInput;
				_BigGreaterOrEqual_output compOutput;
				for(uint8 j = 0 ; j < locals._currentLen; j++) compInput.a.set(j, locals._current.get(j));
				compInput.alen = locals._currentLen;
				for(uint8 j = 0 ; j < locals._tempblen; j++) compInput.b.set(j, locals._tempb.get(j));
				compInput.blen = locals._tempblen;
				CALL(_BigGreaterOrEqual, compInput, compOutput);

				if(!compOutput.result) break;

				_BigMinus_input minusInput;
				_BigMinus_output minusOutput;
				for(uint8 j = 0 ; j < locals._currentLen; j++) minusInput.a.set(j, locals._current.get(j));
				minusInput.alen = locals._currentLen;
				for(uint8 j = 0 ; j < locals._tempblen; j++) minusInput.b.set(j, locals._tempb.get(j));
				minusInput.blen = locals._tempblen;
				
				CALL(_BigMinus, minusInput, minusOutput);
				for(uint8 j = 0 ; j < minusOutput.resultlen; j++) locals._current.set(j, minusOutput.result.get(j));
				locals._currentLen = minusOutput.resultlen;
				count++;
			}
			locals._tempResult.set(i, count + '0');
		}

		output.resultlen = 0;

		locals._flag = 0;
		for(uint8 i = 0; i < locals._currentLen; i++) {
			if(locals._current.get(i) != '0' || locals._flag) {
				locals._flag = 1;
				output.result.set(output.resultlen++, locals._current.get(i));
			}
		}
    _

    struct _BigGreaterOrEqual_locals
    {
		uint8 _tlena;
		uint8 _tlenb;
    }
    PRIVATE_FUNCTION_WITH_LOCALS(_BigGreaterOrEqual)
        // checking if a is positive
		for(uint8 i = 0; i < input.alen; i++) {
			if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;
			return;
		}
		// checking if b is positive
		for(uint8 i = 0; i < input.blen; i++) {
			if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;
			return;
		}

		locals._tlena = input.alen;
		locals._tlenb = input.blen;
		for(uint8 i = 0; i < input.alen; i++) {
			if(input.a.get(i) == '0') _tlena--;
			else break;
		}
		for(uint8 i = 0; i < input.blen; i++) {
			if(input.b.get(i) == '0') locals._tlenb--;
			else break;
		}
		if(_tlena > locals._tlenb) {
			output.result = 1;
			return;
		}
		else if(_tlena < locals._tlenb) {
			output.result = 0;
			return;
		}
		else {
			for(uint8 i = 0 ; i < _tlena; i++) {
				if(input.a.get(i) > input.b.get(i)) {
					output.result = 1;
                    return;
				}
				if(input.a.get(i) < input.b.get(i)) {
					output.result = 0;
                    return;
				}
			}
			output.result = 1;
		}
    _

    struct _BigLessOrEqual_locals
    {
		uint8 _tlena;
		uint8 _tlenb;
    }
    PRIVATE_FUNCTION_WITH_LOCALS(_BigLessOrEqual)
        // checking if a is positive
		for(uint8 i = 0; i < input.alen; i++) {
			if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;
			return;
		}
		// checking if b is positive
		for(uint8 i = 0; i < input.blen; i++) {
			if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;
			return;
		}

		locals._tlena = input.alen;
		locals._tlenb = input.blen;
		for(uint8 i = 0; i < input.alen; i++) {
			if(input.a.get(i) == '0') locals._tlena--;
			else break;
		}
		for(uint8 i = 0; i < input.blen; i++) {
			if(input.b.get(i) == '0') locals._tlenb--;
			else break;
		}
		if(locals._tlena > locals._tlenb) {
			output.result = 0;
			return ;
		}
		else if(locals._tlena < locals._tlenb) {
			output.result = 1;
			return ;
		}
		else {
			for(uint8 i = 0 ; i < locals._tlena; i++) {
				if(input.a.get(i) > input.b.get(i)) {
					output.result = 0;
					return;
				}
				if(input.a.get(i) < input.b.get(i)) {
					output.result = 1; 
					return;
				}
			}
			output.result = 1;
		}
    _

    struct _BigGreater_locals
    {
		uint8 _tlena;
		uint8 _tlenb;
    }
    PRIVATE_FUNCTION_WITH_LOCALS(_BigGreater)
		// checking if a is positive
		for(uint8 i = 0; i < input.alen; i++) {
			if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;
			return;
		}
		// checking if b is positive
		for(uint8 i = 0; i < input.blen; i++) {
			if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;
			return;
		}

		locals._tlena = input.alen;
		locals._tlenb = input.blen;
		for(uint8 i = 0; i < input.alen; i++) {
			if(input.a.get(i) == '0') locals._tlena--;
			else break;
		}
		for(uint8 i = 0; i < input.blen; i++) {
			if(input.b.get(i) == '0') locals._tlenb--;
			else break;
		}
		if(locals._tlena > locals._tlenb) {
			output.result = 1;
			return ;
		}
		else if(locals._tlena < locals._tlenb) {
			output.result = 0;
			return ;
		}
		else {
			for(uint8 i = 0 ; i < locals._tlena; i++) {
				if(input.a.get(i) > input.b.get(i)) {
					output.result = 1;
					return;
				}
				if(input.a.get(i) < input.b.get(i)) {
					output.result = 0;
					return;
				}
			}
			output.result = 0;
		}
    _

    struct _BigLess_locals
    {
        uint8 _tlena;
		uint8 _tlenb;
    }
    PRIVATE_FUNCTION_WITH_LOCALS(_BigLess)
        // checking if a is positive
		for(uint8 i = 0; i < input.alen; i++) {
			if(input.a.get(i) >= '0' && input.a.get(i) <= '9') continue;
			return;
		}
		// checking if b is positive
		for(uint8 i = 0; i < input.blen; i++) {
			if(input.b.get(i) >= '0' && input.b.get(i) <= '9') continue;
			return;
		}

		locals._tlena = input.alen;
		locals._tlenb = input.blen;
		for(uint8 i = 0; i < input.alen; i++) {
			if(input.a.get(i) == '0') locals._tlena--;
			else break;
		}
		for(uint8 i = 0; i < input.blen; i++) {
			if(input.b.get(i) == '0') locals._tlenb--;
			else break;
		}
		if(locals._tlena > locals._tlenb) {
			output.result = 0;
			return ;
		}
		else if(locals._tlena < locals._tlenb) {
			output.result = 1;
			return ;
		}
		else {
			for(uint8 i = 0 ; i < locals._tlena; i++) {
				if(input.a.get(i) > input.b.get(i)) {
					output.result = 0; 
					return;
				}
				if(input.a.get(i) < input.b.get(i)) {
					output.result = 1; 
					return;
				}
			}
			output.result = 0;
		}
    _
	// write PRIVATE_PROCEDURE_WITH_LOCALS
    
    struct _MintMicroToken_locals
    {
        bool _balanceFound;
        _MicroTokenBalance _newBalance;
    }
    PRIVATE_PROCEDURE_WITH_LOCALS(_MintMicroToken)
        locals._balanceFound = false;
        output.mintedMicroTokenAmount = 0;
        // Iterate over balances to find the matching balance for the issuer and asset
        for (auto &balance : _microTokenBalances)
        {
            if (balance.issuer == input.issuer
                && balance.assetName == input.assetName
                && balance.owner == qpi.invocator())
            {
                // Add the minted amount to the existing balance
                balance.balance += input.microTokenAmount;
                locals.balanceFound = true;
                output.mintedMicroTokenAmount = input.microTokenAmount;
                break;
            }
        }

        // If no existing balance was found, create a new balance entry
        if (!locals.balanceFound)
        {
            locals._newBalance.issuer = input.issuer;
            locals._newBalance.assetName = input.assetName;
            locals._newBalance.owner = qpi.invocator();
            locals._newBalance.balance = input.microTokenAmount;
            _microTokenBalances.push_back(locals._newBalance);
            output.mintedMicroTokenAmount = input.microTokenAmount;
        }
    _

    struct _BurnMicroToken_locals
    {
        bool _balanceFound;
    }
    PRIVATE_PROCEDURE_WITH_LOCALS(_BurnMicroToken)
        locals._balanceFound = false;
        output.burntMicroTokenAmount = 0;

        // Iterate over balances to find the matching balance for the issuer and asset
        for (auto &balance : _microTokenBalances)
        {
            if (balance.issuer == input.issuer
                && balance.assetName == input.assetName
                && balance.owner == qpi.invocator())
            {
                if (balance.balance >= input.microTokenAmount)
                {
                    // Deduct the amount to be burned from the existing balance
                    balance.balance -= input.microTokenAmount;
                    locals._balanceFound = true;
                    output.burntMicroTokenAmount = input.microTokenAmount;
                }
                break;
            }
        }
    _

    struct _LockExpensiveToken_locals
    {
        
    }
    PRIVATE_PROCEDURE_WITH_LOCALS(_LockExpensiveToken)
		if (qpi.numberOfPossessedShares(input.issuer, input.assetName, qpi.invocator(), qpi.invocator(), SELF_INDEX, SELF_INDEX) < input.expensiveTokenAmount)
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
    }
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
    PUBLIC_FUNCTION(MicroTokenAllowance)
        output.balance = 0;
        for (const auto& allowance : _microTokenAllowances)
        {
            if (allowance.issuer == input.issuer &&
                allowance.assetName == input.assetName &&
                allowance.recipient == input.recipient &&
                allowance.spender == input.spender)
            {
                output.balance = allowance.balance;
                break;
            }
        }
	_

    // write PUBLIC_FUNCTION_WITH_LOCALS
	struct BalanceOfMicroToken_locals
	{
		_BalanceOfMicroToken_input _balanceOfMicroToken_input;
		_BalanceOfMicroToken_output _balanceOfMicroToken_output;
	}
	PUBLIC_FUNCTION_WITH_LOCALS(BalanceOfMicroToken)
		locals._balanceOfMicroToken_input.issuer = input.issuer;
		locals._balanceOfMicroToken_input.assetName = input.assetName;
		locals._balanceOfMicroToken_input.owner = input.owner;
		CALL(_BalanceOfMicroToken, locals._balanceOfMicroToken_input, locals._balanceOfMicroToken_output);
		output.balance = locals._balanceOfMicroToken_output.balance;
    _

	struct BigNumToStr_locals
	{
		_BigNumToStr_input _input;
		_BigNumToStr_output _output;
	}
    PUBLIC_FUNCTION_WITH_LOCALS(BigNumToStr)
		locals._input.a = input.a;
		CALL(_BigNumToStr, locals._input, locals._output);
		output.len = locals._output.len;
		output.result = locals._output.result;
	_
	
	struct BigStrToNum_locals
	{
		_BigStrToNum_input _input;
		_BigStrToNum_output _output;
	}
    PUBLIC_FUNCTION_WITH_LOCALS(BigStrToNum)
		locals._input.len = input.len;
		locals._input.a = input.a;
		CALL(_BigStrToNum, locals._input, locals._output);
		output.result = locals.output.result;
	_

	struct BigPlus_locals
	{
		_BigPlus_input _input;
		_BigPlus_output _output;
	}
	PUBLIC_FUNCTION_WITH_LOCALS(BigPlus)
		locals._input.alen = input.alen;
		locals._input.blen = input.blen;
		locals._input.a = input.a;
		locals._input.b = input.b;
		CALL(_BigPlus, locals._input, locals.output);
		output.resultlen = locals.output.resultlen;
		output.result = locals.output.result;
	_

	struct BigMinus_locals
	{
		_BigMinus_input _input;
		_BigMinus_output _output;
	}
	PUBLIC_FUNCTION_WITH_LOCALS(BigMinus)
		locals._input.alen = input.alen;
		locals._input.blen = input.blen;
		locals._input.a = input.a;
		locals._input.b = input.b;
		CALL(_BigMinus, locals._input, locals.output);
		output.resultlen = locals._output.resultlen;
		output.result = locals._output.result;
	_

	struct BigMultiply_locals
	{
		_BigMultiply_input _input;
		_BigMultiply_output _output;
	}
	PUBLIC_FUNCTION_WITH_LOCALS(BigMultiply)
		locals._input.alen = input.alen;
		locals._input.blen = input.blen;
		locals._input.a = input.a;
		locals._input.b = input.b;
		CALL(_BigMultiply, locals.input, locals.output);
		output.resultlen = locals.output.resultlen;
		output.result = locals.output.result;
	_

	struct BigDiv_locals
	{
		_BigDiv_input _input;
		_BigDiv_output _output;
	}
	PUBLIC_FUNCTION_WITH_LOCALS(BigDiv)
		locals._input.alen = input.alen;
		locals._input.blen = input.blen;
		locals._input.a = input.a;
		locals._input.b = input.b;
		CALL(_BigDiv, locals.input, locals.output);
		output.resultlen = locals.output.resultlen;
		output.result = locals.output.result;
	_

	struct BigModulus_locals
	{
		_BigModulus_input _input;
		_BigModulus_output _output;
	}
	PUBLIC_FUNCTION_WITH_LOCALS(BigModulus)
		locals._input.alen = input.alen;
		locals._input.blen = input.blen;
		locals._input.a = input.a;
		locals._input.b = input.b;
		CALL(_BigModulus, locals.input, locals.output);
		output.resultlen = locals.output.resultlen;
		output.result = locals.output.result;
	_

	struct BigGreaterOrEqual_locals
	{
		_BigGreaterOrEqual_input _input;
		_BigGreaterOrEqual_output _output;
	}
	PUBLIC_FUNCTION_WITH_LOCALS (BigGreaterOrEqual)
		locals._input.alen = input.alen;
		locals._input.blen = input.blen;
		locals._input.a = input.a;
		locals._input.b = input.b;
		CALL(_BigGreaterOrEqual, locals.input, locals.output);
		output.result = locals.output.result;
	_

	struct BigLessOrEqual_locals
	{
		_BigLessOrEqual_input _input;
		_BigLessOrEqual_output _output;
	}
	PUBLIC_FUNCTION_WITH_LOCALS (BigLessOrEqual)
		locals._input.alen = input.alen;
		locals._input.blen = input.blen;
		locals._input.a = input.a;
		locals._input.b = input.b;
		CALL(_BigLessOrEqual, locals.input, locals.output);
		output.result = locals.output.result;
	_

	struct BigGreater_locals
	{
		_BigGreater_input _input;
		_BigGreater_output _output;
	}
	PUBLIC_FUNCTION_WITH_LOCALS (BigGreater)
		locals._input.alen = input.alen;
		locals._input.blen = input.blen;
		locals._input.a = input.a;
		locals._input.b = input.b;
		CALL(_BigGreater, locals.input, locals.output);
		output.result = locals.output.result;
	_

	struct BigLess_locals
	{
		_BigLess_input _input;
		_BigLess_output _output;
	}
	PUBLIC_FUNCTION_WITH_LOCALS (BigLess)
		locals._input.alen = input.alen;
		locals._input.blen = input.blen;
		locals._input.a = input.a;
		locals._input.b = input.b;
		CALL(_BigLess, locals.input, locals.output);
		output.result = locals.output.result;

    // write PUBLIC_PROCEDURE_WITH_LOCALS
    _

    struct ApproveMicroToken_locals
    {
        bool _allowanceFound;
        _MicroTokenAllowance _newAllowance;
    }

    PUBLIC_PROCEDURE_WITH_LOCALS(ApproveMicroToken)
        if (qpi.invocationReward() > 0)
        {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
        }
        
        locals._allowanceFound = false;

        for (auto& allowance : _microTokenAllowances)
        {
            if (allowance.issuer == input.issuer &&
                allowance.assetName == input.assetName &&
                allowance.spender == qpi.invocator() &&
                allowance.recipient == input.recipient)
            {
                allowance.balance = input.microTokenAmount;
                output.approvedMicroTokenAmount = input.microTokenAmount;
                locals._allowanceFound = true;
            }
        }
        
        if (!locals.allowanceFound)
        {
            locals._newAllowance.issuer = input.issuer;
            locals._newAllowance.assetName = input.assetName;
            locals._newAllowance.spender = qpi.invocator();
            locals._newAllowance.recipient = input.recipient;
            locals._newAllowance.balance = input.microTokenAmount;

            _microTokenAllowances.push_back(locals._newAllowance);
            output.approvedMicroTokenAmount = input.microTokenAmount;
        }
    _

    struct TransferMicroToken_locals
    {
        bool _balanceFound;
        bool _recipientBalanceFound;
        _MicroTokenBalance _newBalance;
    }

    _

    PUBLIC_PROCEDURE_WITH_LOCALS(TransferMicroToken)
        if (qpi.invocationReward() > 0)
        {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
        }
        output.transferredMicroTokenAmount = 0;
        locals._balanceFound = false;
        locals._recipientBalanceFound = false;
        for (auto& balance : _microTokenBalances)
        {
            if (balance.issuer == input.issuer &&
                balance.assetName == input.assetName &&
                balance.owner == qpi.invocator())
            {
                if (balance.balance >= input.microTokenAmount)
                {
                    // Deduct the micro tokens from the invocator's balance
                    balance.balance -= input.microTokenAmount;
                    locals._balanceFound = true;
                }
                break;
            }
        }
        if (locals._balanceFound)
        {
            for (auto& balance : _microTokenBalances)
            {
                if (balance.issuer == input.issuer &&
                    balance.assetName == input.assetName &&
                    balance.owner == input.recipient)
                {
                    // Add the micro tokens to the recipient's balance
                    balance.balance += input.microTokenAmount;
                    locals._recipientBalanceFound = true;
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
                _microTokenBalances.push_back(locals._newBalance);
                output.transferredMicroTokenAmount = input.microTokenAmount;
            }
        }
    _

    struct TransferFromMicroToken_locals
    {
        bool _allowanceFound;
        bool _spenderBalanceFound;
        bool _recipientBalanceFound;
        _MicroTokenBalance newBalance;
    }

    PUBLIC_PROCEDURE_WITH_LOCALS(TransferFromMicroToken)
        if (qpi.invocationReward() > 0)
        {
            qpi.transfer(qpi.invocator(), qpi.invocationReward());
        }
        locals._allowanceFound = false;
        locals._spenderBalanceFound = false;
        locals._recipientBalanceFound = false;
        output.transferredMicroTokenAmount = 0;
        for (auto& allowance : _microTokenAllowances)
        {
            if (allowance.issuer == input.issuer &&
                allowance.assetName == input.assetName &&
                allowance.recipient == input.recipient &&
                allowance.spender == input.spender)
            {
                if (allowance.balance >= input.microTokenAmount)
                {
                    // Deduct the micro tokens from the allowance
                    allowance.balance -= input.microTokenAmount;
                    locals._allowanceFound = true;
                }
                break;
            }
        }

        if (locals._allowanceFound)
        {
            for (auto& balance : _microTokenBalances)
            {
                if (balance.issuer == input.issuer &&
                    balance.assetName == input.assetName &&
                    balance.owner == input.spender)
                {
                    if (balance.balance >= input.microTokenAmount)
                    {
                        // Deduct the micro tokens from the owner's balance
                        balance.balance -= input.microTokenAmount;
                        locals._spenderBalanceFound = true;
                    }
                    break;
                }
            }
            if (locals._spenderBalanceFound)
            {
                for (auto& balance : _microTokenBalances)
                {
                    if (balance.issuer == input.issuer &&
                        balance.assetName == input.assetName &&
                        balance.owner == input.recipient)
                    {
                        // Add the micro tokens to the recipient's balance
                        balance.balance += input.microTokenAmount;
                        locals._recipientBalanceFound = true;

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
                    _microTokenBalances.push_back(locals._newBalance);

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
		id _zeroIssuer;
	}
    PUBLIC_PROCEDURE_WITH_LOCALS(ConvertToMicroToken)
		if (qpi.invocationReward() > 0)
		{
			qpi.transfer(qpi.invocator(), qpi.invocationReward());
		}
		// check expensive token by name and public key
		locals._zeroIssuer = _mm256_setzero_si256();
		if (!_mm256_testz_si256(input.issuer, locals._zeroIssuer))
		{
			return;
		}
		//
		if (qpi.numberOfPossessedShares(input.issuer, input.assetName, qpi.invocator(), qpi.invocator(), SELF_INDEX, SELF_INDEX) < input.expensiveTokenAmount)
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
	}
    PUBLIC_PROCEDURE_WITH_LOCALS(ConvertToExpensiveToken)
		if (qpi.invocationReward() > 0)
		{
			qpi.transfer(qpi.invocator(), qpi.invocationReward());
		}

		locals._balanceOfMicroToken_input.issuer = input.issuer;
		locals._balanceOfMicroToken_input.assetName = input.assetName;
		locals._balanceOfMicroToken_input.owner = qpi.invocator();
		CALL(BalanceOfMicroToken, locals._balanceOfMicroToken_input, locals._balanceOfMicroToken_output);
		if(locals._balanceOfMicroToken_output.balance < input.microTokenAmount)
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
			output.expensiveTokenAmount = locals._unLockExpensiveToken_output.expensiveTokenAmount;
		}
    
    _

    // write PUBLIC_PROCEDURE

    PUBLIC_PROCEDURE(CreateLiquid)

    _

    PUBLIC_PROCEDURE(AddLiquidity)
    
    _

    PUBLIC_PROCEDURE(RemoveLiquidity)
    
    _

    PUBLIC_PROCEDURE(Swap)
    
    _

    REGISTER_USER_FUNCTIONS_AND_PROCEDURES
        REGISTER_USER_FUNCTION(MicroTokenAllowance, 1);
		REGISTER_USER_FUNCTION(BigNumToStr, 2);
		REGISTER_USER_FUNCTION(BigStrToNum, 3);
		REGISTER_USER_FUNCTION(BigPlus, 4);
		REGISTER_USER_FUNCTION(BigMinus, 5);
		REGISTER_USER_FUNCTION(BigMultiply, 6);
		REGISTER_USER_FUNCTION(BigDiv, 7);
		REGISTER_USER_FUNCTION(BigModulus, 8);
		REGISTER_USER_FUNCTION(BigGreaterOrEqual, 9);
		REGISTER_USER_FUNCTION(BigLessOrEqual, 10);
		REGISTER_USER_FUNCTION(BigGreater, 11);
		REGISTER_USER_FUNCTION(BigLess, 12);

        REGISTER_USER_PROCEDURE(ApproveMicroToken, 13);
        REGISTER_USER_PROCEDURE(TransferMicroToken, 14);
        REGISTER_USER_PROCEDURE(TransferFromMicroToken, 15);
        REGISTER_USER_PROCEDURE(ConvertToMicroToken, 16);
        REGISTER_USER_PROCEDURE(ConvertToExpensiveToken, 17);
        REGISTER_USER_PROCEDURE(CreateLiquid, 18);
        REGISTER_USER_PROCEDURE(AddLiquidity, 19);
        REGISTER_USER_PROCEDURE(RemoveLiquidity, 20);
        REGISTER_USER_PROCEDURE(Swap, 21);
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
