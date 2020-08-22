class x :
    def __init__(self):
        self.hello = 'hi'

    def greeting(self):
        print(self.hello)

x1 = x()
x1.greeting()


class Person:
    def __init__(self, name, age, address, wallet):
        self.name = name
        self.age = age
        self.address = address
        self.__wallet = wallet  # 변수 앞에 __를 붙여서 비공개 속성으로 만듦

    def pay(self, amount):
        self.__wallet -= amount  # 비공개 속성은 클래스 안의 메서드에서만 접근할 수 있음
        print('이제 {0}원 남았네요.'.format(self.__wallet))
maria = Person('마리아', 20, '서울시 서초구 반포동', 10000)
maria.pay(3000)   # 클래스 바깥에서 비공개 속성에 접근하면 에러가 발생함


class Person:
    count = 0

    def __init__(self):
        self.count =0  # 인스턴스가 만들어질 때
        # 클래스 속성 count에 1을 더함

    @classmethod
    def print_count(self):

        print('{0}명 생성되었습니다.'.format(self.count))  # cls로 클래스 속성에 접근


james = Person()
maria = Person()

james.print_count()
Person.print_count()