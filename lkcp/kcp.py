from . import core

__all__ = ["KcpObj"]

class KcpObj:
    def __init__(self, conv, id, callback):
        self.cobj = core.lkcp_create(conv, id, callback)

    def wndsize(self, sndwnd, rcvwnd):
        core.lkcp_wndsize(self.cobj, sndwnd, rcvwnd)

    def nodelay(self, nodelay, interval, resend, nc):
        return core.lkcp_nodelay(self.cobj, nodelay, interval, resend, nc)

    def check(self, current):
        return core.lkcp_check(self.cobj, current)

    def update(self, current):
        core.lkcp_update(self.cobj, current)

    def send(self, data):
        return core.lkcp_send(self.cobj, data)

    def input(self, data):
        return core.lkcp_input(self.cobj, data)

    def recv(self):
        return core.lkcp_recv(self.cobj)

    def flush(self):
        core.lkcp_flush(self.cobj)