import transfertestserver

print(transfertestserver.globalval)
transfertestserver.changeGlobalVal(12345)
transfertestserver.globalval=12345
print(transfertestserver.globalval)
