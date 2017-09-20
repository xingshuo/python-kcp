sudo pip install -r requirements.txt
bin/python setup.py build
bin/python setup.py install
rm -rf build dist lkcp.egg-info
